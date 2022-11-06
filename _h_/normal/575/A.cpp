#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<ll,ll> pll;
const int mx = 5e4+10;
ll p=2,n,k,m,s[mx];

template<class T> 
struct ST{
	int n;
	vector<T> t;
	T id;
	ST(int a, T z) : n(a), id(z), t(2*n,z) {}
	void build(){
		for(int pos = n; pos --> 1;)
			t[pos] = t[pos<<1]*t[pos<<1|1];
	}
	T query(int l, int r){
		T lans = id, rans = id;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(l & 1)
				lans = lans * t[l++];
			if(r & 1)
				rans = t[--r] * rans;
		}
		return lans * rans;
	}
};

struct Mat{
	ll a,b,c,d;
	Mat(ll x,ll y,ll z,ll w):a(x%p),b(y%p),c(z%p),d(w%p){}
	Mat(){}
} id(1,0,0,1), cyc;

Mat operator*(const Mat &y, const Mat &x){
	return Mat(x.a*y.a + x.b*y.c, x.a*y.b+x.b*y.d,
		x.c*y.a+x.d*y.c, x.c*y.b+x.d*y.d);
}

Mat mexp(Mat x, ll e){
	Mat ans = id;
	for(; e; e /= 2, x = x*x)
		if(e&1)
			ans = ans * x;
	return ans;
}

Mat subprod(ll l, ll r, ST<Mat> &prp){
	if(r/n == l/n)
		return prp.query(l%n, r%n);
	return prp.query(l%n,n)*mexp(cyc,r/n-l/n-1)*prp.query(0,r%n);
}

int main(){
	scanf("%lld %lld %lld ",&k,&p,&n);
	if(k < 2){
		printf("%lld",k%p);
		return 0;
	}
	ST<Mat> prp(n,id);
	rep(i,0,n)
		scanf("%lld ",s+i);
	s[n] = s[0];
	rep(i,0,n)
		prp.t[i+n] = Mat(s[i+1],s[i],1,0);
	prp.build();
	cyc = prp.query(0,n);
	pll jv[mx];
	scanf("%lld ",&m);
	rep(i,0,m)
		scanf("%lld %lld ",&jv[i].first,&jv[i].second);
	sort(jv,jv+m);
	Mat cur = id;
	ll pos = 0, prev = s[0];
	rep(i,0,m){
		ll j = jv[i].first, v = jv[i].second;
		if(j >= k)
			break;
		if(j == pos+1){
			cur = cur * Mat(v,prev,1,0);
		} else {
			cur = cur * Mat(s[(pos+1)%n],prev,1,0);
			cur = cur * subprod(pos+1,j-1,prp);
			cur = cur * Mat(v,s[(j-1)%n],1,0);
		}
		pos = j;
		prev = v;
	}
	if(pos+1 < k){
		cur = cur * Mat(s[(pos+1)%n],prev,1,0);
		cur = cur * subprod(pos+1,k-1,prp);
	}
	printf("%lld \n",cur.a);
}