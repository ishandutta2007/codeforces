#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

ll n, q, k, u, v, x, y, t, l, r, ans;
ll A[MAXN], ps[MAXN];
pll seg[MAXN<<1];

pll combine(pll x, pll y){ return {min(x.first, y.first), max(x.second, y.second)};}
void Set(int pos, pll val){
	for (seg[pos+=n]=val; pos>1; pos>>=1) seg[pos>>1]=combine(seg[pos], seg[pos^1]);
}
pll Get(int l, int r){
	pll res=seg[0];
	for (l+=n, r+=n; l<r; l>>=1, r>>=1){
		if (l&1) res=combine(res, seg[l++]);
		if (r&1) res=combine(res, seg[--r]);
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>q;
	for (int i=1; i<=n; i++) cin>>A[i];
	fill(seg, seg+MAXN*2, pll(INF, -INF));
	for (int i=1; i<=n; i++){
		cin>>x;
		A[i]-=x;
		ps[i]=ps[i-1]+A[i];
		Set(i, {ps[i], ps[i]});
	}
	while (q--){
		cin>>l>>r;
		if (ps[r]-ps[l-1]){
			cout<<"-1\n";
			continue ;
		}
		r++;
		pll p=Get(l, r);
		p.first-=ps[l-1];
		p.second-=ps[l-1];
		if (p.second>0){
			cout<<"-1\n";
			continue ;
		}
		cout<<-p.first<<"\n";
	}
	
	return 0;
}