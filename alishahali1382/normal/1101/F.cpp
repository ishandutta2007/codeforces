#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 410, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
//ld f[MAXN];
ll A[MAXN];
pair<pii, pii> B[250000];
mt19937 rng(time(0));
/*
int go(int n){
	for (int i=0; i<n; i++) A[i]=i;
	shuffle(A, A+n, rng);
	int res=0, mx=-1;
	for (int i=0; i<n; i++) if (A[i]>mx){
		mx=A[i];
		res++;
	}
	//cerr<<"random n="<<n<<"  -->  "<<res<<'\n';
	return res;
}*/

bool check(ll V, pair<pii, pii> p){
	ll s=p.first.first, f=p.first.second, c=p.second.first, r=p.second.second;
	ll curr=V;
	while (s<f){
		ll d=A[s+1]-A[s];
		d*=c;
		if (V<d) return 0;
		s++;
		if (d<=curr) curr-=d;
		else{
			curr=V;
			curr-=d;
			r--;
			if (r<0) return 0;
		}
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	/*
	f[0]=0;
	f[1]=1;
	ld sum=1;
	for (int n=2; n<MAXN; n++){
		f[n]=sum/n+1;
		sum+=f[n];
	}
	int N=1000000;
	debug(f[N])
	ld shit=0, ted=100;
	for (int i=0; i<ted; i++){
		shit+=go(N);
		if (i%10==0) debug(i)
	}
	cerr<<"in reality : "<<shit/ted<<'\n';
	*/
	
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=0; i<m; i++) cin>>B[i].first.first>>B[i].first.second>>B[i].second.first>>B[i].second.second;
	shuffle(B, B+m, rng);
	for (int i=0; i<m; i++){
		if (check(ans, B[i])) continue ;
		ll dwn=ans, up=1e18+100;
		while (up-dwn>1){
			ll mid=(dwn+up)>>1;
			if (check(mid, B[i])) up=mid;
			else dwn=mid;
		}
		ans=up;
	}
	cout<<ans<<'\n';
	
	return 0;
}