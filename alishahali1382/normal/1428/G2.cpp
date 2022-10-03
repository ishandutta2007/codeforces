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
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=1000010, D=6;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll F[D], tav[D+1];
ll dp[MAXN], dpt[MAXN];

struct Segment{
	ll seg[MAXN*2+10];
	Segment(){
		memset(seg, -31, sizeof(seg));
	}
	void Build(){
		for (int i=MAXN*2-1; i>1; i--) seg[i>>1]=max(seg[i], seg[i^1]);
	}
	void Set(int pos, ll val){
		seg[pos+=MAXN]=val;
	}
	ll Get(int l, int r){
		l=max(l, 0);
		r=min(MAXN, r);
		ll res=-INF;
		for (l+=MAXN, r+=MAXN; l<r; l>>=1, r>>=1){
			if (l&1) res=max(res, seg[l++]);
			if (r&1) res=max(res, seg[--r]);
		}
		return res;
	}
} seg[3];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>k>>F[0]>>F[1]>>F[2]>>F[3]>>F[4]>>F[5];
	tav[0]=1;
	for (int i=1; i<=D; i++) tav[i]=tav[i-1]*10;
	
	memset(dpt, -31, sizeof(dpt));
	dpt[0]=0;
	for (int i=D-1; ~i; i--){
//		debug(i)
		for (int j=0; j*tav[i]<MAXN; j++){
			seg[j%3].Set(j/3, dpt[j*tav[i]] - (j/3)*F[i]);
		}
		seg[0].Build();
		seg[1].Build();
		seg[2].Build();
		
		memset(dp, -31, sizeof(dp));
		int tav3=3*tav[i];
		for (int x=0; x*tav[i]<MAXN; x++){
			int t=min(k*3, x/3ll);
			dp[x*tav[i]]=seg[x%3].Get(x/3-t, x/3+1)+(x/3)*F[i];
			for (int a0=0; a0<10; a0++) if ((a0%3) && a0<=x){
				int xx=x-a0;
				t=min((k-1)*3, xx/3ll);
				dp[x*tav[i]]=max(dp[x*tav[i]], seg[xx%3].Get(xx/3-t, xx/3+1)+(xx/3)*F[i]);	
			}
		}/*
		debug(dp[20])
		debug(dp[30])
		debug(dp[40])
		debug(dp[50])
		*/
		memcpy(dpt, dp, sizeof(dpt));
	}
//	debug("done")
	int q;
	cin>>q;
	while (q--){
		cin>>n;
		cout<<dpt[n]<<"\n";
	}
	
	return 0;
}