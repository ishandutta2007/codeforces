#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
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
const int MAXN = 10000010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans, out;
short mob[MAXN];
int cnt[MAXN];
ll tav[MAXN];
ll val[MAXN];
int cop[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	mob[1]=1;
	for (int i=1; i<MAXN; i++) if (mob[i]) for (int j=i+i; j<MAXN; j+=i) mob[j]-=mob[i];
	for (int i=1; i<MAXN; i++) tav[i]=(2*tav[i-1]+1)%mod;
	
	//for (int i=1; i<=12; i++) debug2(i, mob[i])
	
	cin>>n;
	for (int i=1; i<=n; i++) cin>>x, cnt[x]++;
	for (int i=1; i<MAXN; i++) for (int j=i+i; j<MAXN; j+=i) cnt[i]+=cnt[j];
	for (int i=1; i<MAXN; i++) if (mob[i] && cnt[i]) for (int j=i; j<MAXN; j+=i) cop[j]+=cnt[i]*mob[i];
	
	//for (int i=1; i<=10; i++) debug2(i, cop[i])
	
	for (int i=MAXN-1; i; i--){
		val[i]=tav[cnt[i]];
		for (int j=i+i; j<MAXN; j+=i) val[i]-=val[j];
		val[i]%=mod;
	}
	for (int i=2; i<MAXN; i++) out=(out+val[i]*cop[i])%mod;
	
	cout<<(out+mod)%mod<<'\n';
	
	return 0;
}
/*
      ___           ___                            ___           ___           ___           ___           ___           ___
     /\  \         /\__\      ___                 /\  \         /\__\         /\  \         /\__\         /\  \         /\__\      ___
    /::\  \       /:/  /     /\  \               /::\  \       /:/  /        /::\  \       /:/  /        /::\  \       /:/  /     /\  \
   /:/\:\  \     /:/  /      \:\  \             /:/\ \  \     /:/__/        /:/\:\  \     /:/__/        /:/\:\  \     /:/  /      \:\  \
  /::\~\:\  \   /:/  /       /::\__\           _\:\~\ \  \   /::\  \ ___   /::\~\:\  \   /::\  \ ___   /::\~\:\  \   /:/  /       /::\__\
 /:/\:\ \:\__\ /:/__/     __/:/\/__/          /\ \:\ \ \__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/__/     __/:/\/__/
 \/__\:\/:/  / \:\  \    /\/:/  /             \:\ \:\ \/__/ \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \:\  \    /\/:/  /
      \::/  /   \:\  \   \::/__/               \:\ \:\__\        \::/  /       \::/  /       \::/  /       \::/  /   \:\  \   \::/__/
      /:/  /     \:\  \   \:\__\                \:\/:/  /        /:/  /        /:/  /        /:/  /        /:/  /     \:\  \   \:\__\
     /:/  /       \:\__\   \/__/                 \::/  /        /:/  /        /:/  /        /:/  /        /:/  /       \:\__\   \/__/
     \/__/         \/__/                          \/__/         \/__/         \/__/         \/__/         \/__/         \/__/
*/