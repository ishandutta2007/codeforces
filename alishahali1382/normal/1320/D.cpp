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
const int T=3;
const ll Base[T]={10007, 456321, 3492}, Mod[T]={1000000007, 998244353, 1000000009};
const int MAXN = 200010, LOG=20;
typedef array<ll, T> Hash;

int n, m, k, u, v, x, y, t, a, b, len, ans;
int A[MAXN], cnt[MAXN];
Hash H[MAXN], Tav[MAXN], Tav2[MAXN];
string S;

Hash Get(int l, int r){ // [l, r]
	int ted=r-l+1 - (cnt[r]-cnt[l-1]);
	
	Hash res;
	for (int j=0; j<T; j++){
		res[j]=(H[r][j]-H[l-1][j]*Tav[ted][j])%Mod[j];
		if (res[j]<0) res[j]+=Mod[j];
	}
	/*
	debug(ted)
	debug(res[2])
	debug(Tav2[2][2])
	*/
	if (cnt[l-1]&1){
		for (int j=0; j<T; j++) res[j]=(Tav2[ted][j]-res[j]+Mod[j])%Mod[j];
	}
	return res;
}

int Query(){
	cin>>a>>b>>len;
	if (cnt[a+len-1]-cnt[a-1]!=cnt[b+len-1]-cnt[b-1]) kill("NO")
	
	Hash h1=Get(a, a+len-1), h2=Get(b, b+len-1);
	
	if (h1==h2) cout<<"YES\n";
	else cout<<"NO\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=0; i<T; i++) Tav[0][i]=1;
	for (int i=1; i<MAXN; i++) for (int j=0; j<T; j++){
		Tav[i][j]=(Tav[i-1][j]*Base[j])%Mod[j];
		Tav2[i][j]=(Tav2[i-1][j] + Tav[i-1][j])%Mod[j];
	}
	
	cin>>n>>S;
	S="."+S;
	for (int i=1; i<=n; i++){
		A[i]=S[i]-'0';
		cnt[i]=cnt[i-1]+A[i];
		H[i]=H[i-1];
		if (A[i]) continue ;
		for (int j=0; j<T; j++) H[i][j]=(H[i][j]*Base[j] + (cnt[i]%2))%Mod[j];
	}
	/*
	//debugv(Get(1, 4))
	debug(Get(7, 10)[2])
	
	return 0;*/
	
	cin>>m;
	while (m--) Query();
	
	return 0;
}
/*
10
1100100110
7
1 5 4
1 5 3
1 8 3
1 7 4
1 5 5
1 5 6
2 7 4


10
1100100110
1
1 7 4

*/