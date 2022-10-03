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
const int MAXN=300010, SQ=1200;

struct Fenwick{
	ll fen[MAXN];
	void reset(){
		memset(fen, 0, sizeof(fen));
	}
	Fenwick(){
		reset();
	}
	void add(int pos, ll x){
		for (; pos<MAXN; pos+=pos&-pos) fen[pos]+=x;
	}
	ll get(int pos){
		ll res=0;
		for (; pos; pos-=pos&-pos) res+=fen[pos];
		return res;
	}
} fen1, fen2;

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN], cnt[MAXN];
ll ans[MAXN], val[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	int tedbig=0; // A[i]>SQ
	for (int k=1; k<=n; k++){
		// A[k]%A[i]
		for (int i=1; i<=SQ; i++) ans[k]+=1ll*cnt[i]*(A[k]%i);
		ans[k]+=1ll*A[k]*tedbig;
		for (int t=0; t<=MAXN/SQ; t++){
			int l=max(SQ, A[k]/(t+1)), r=(!t?MAXN-1:A[k]/t);
			if (l>r) continue ;
			ll sum=fen2.get(r)-fen2.get(l);
			ans[k]-=sum*t;
		}
//		debug2(k, ans[k])
		
		// A[i]%A[k]
		if (A[k]<=SQ) ans[k]+=val[A[k]];
		else{
			ans[k]+=fen2.get(MAXN-1);
			for (int t=0; t*A[k]<MAXN; t++){
				int l=t*A[k], r=min(MAXN, l+A[k]);
				ll sum=fen1.get(r-1)-fen1.get(max(0, l-1));/*
				if (k==4 && sum){
					debug2(l, r)
					debug2(sum, t)
				}*/
				ans[k]-=t*sum*A[k];
			}
		}
//		debug2(k, ans[k])
		
		fen1.add(A[k], +1);
		fen2.add(A[k], A[k]);
		if (A[k]>SQ) tedbig++;
		cnt[A[k]]++;
		for (int i=1; i<=SQ; i++) val[i]+=(A[k]%i);
	}
	for (int k=1; k<=n; k++) cout<<(ans[k]+=ans[k-1])<<" \n"[k==n];
	
	return 0;
}
/*
3
6 2 7


*/