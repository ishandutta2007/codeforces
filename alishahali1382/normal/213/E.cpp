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
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int T=2, Base[]={10007, 12345}, Mod[]={1000000007, 998244353};
const int MAXN = 200010;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], B[MAXN], pos[MAXN];
int Cnt[MAXN<<2];
int tav[T][MAXN];
array<int, T> Hash[MAXN<<2];
array<int, T> hasha, shit;

void Set(int id, int tl, int tr, int pos, int val){
	if (pos<tl || tr<=pos) return ;
	if (tr-tl==1){
		for (int i=0; i<T; i++) Hash[id][i]=val;
		Cnt[id]=(val>0);
		return ;
	}
	int mid=(tl+tr)>>1;
	Set(id<<1, tl, mid, pos, val);
	Set(id<<1 | 1, mid, tr, pos, val);
	Cnt[id]=Cnt[id<<1] + Cnt[id<<1 | 1];
	for (int i=0; i<T; i++) Hash[id][i]=(1ll*Hash[id<<1][i]*tav[i][Cnt[id<<1 | 1]] + Hash[id<<1 | 1][i])%Mod[i];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=0; i<T; i++){
		tav[i][0]=1;
		for (int j=1; j<MAXN; j++) tav[i][j]=(1ll*tav[i][j-1]*Base[i])%Mod[i];
	}
	
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=0; i<T; i++){
		for (int j=1; j<=n; j++){
			hasha[i]=(1ll*hasha[i]*Base[i] + A[j])%Mod[i];
			shit[i]=(1ll*shit[i]*Base[i] + 1)%Mod[i];
		}
	}
	for (int i=1; i<=m; i++) cin>>B[i], pos[B[i]]=i;
	for (int i=1; i<=m; i++){
		Set(1, 1, m+1, pos[i], i);
		if (i>n) Set(1, 1, m+1, pos[i-n], 0);
		if (i>=n){
			ans+=(Hash[1]==hasha);
			for (int j=0; j<T; j++) hasha[j]=(hasha[j]+shit[j])%Mod[j];
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}