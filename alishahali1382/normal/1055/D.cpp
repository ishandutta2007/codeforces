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

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=3010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int L[MAXN], R[MAXN];
int f[MAXN];
bool good[MAXN];
string W[MAXN], WW[MAXN], S, T;

int KMP(string &S, string &T){
	int k=0;
	for (int i=1; i<S.size(); i++){
		while (k && S[k]!=S[i]) k=f[k];
		f[i+1]=k+=(S[k]==S[i]);
	}
	
	k=0;
	for (int i=0; i<T.size(); i++){
		while (k && S[k]!=T[i]) k=f[k];
		k+=(S[k]==T[i]);
		if (k==S.size()) return i;
	}
	return -1;
}

bool KMP2(string &S, string &T, int pos){
	int k=0;
	for (int i=1; i<S.size(); i++){
		while (k && S[k]!=S[i]) k=f[k];
		f[i+1]=k+=(S[k]==S[i]);
	}
	
	k=0;
	for (int i=0; i<T.size(); i++){
		while (k && S[k]!=T[i]) k=f[k];
		k+=(S[k]==T[i]);
		if (i==pos) return (k==S.size());
		if (k==S.size()) k=f[k];
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>W[i];
	for (int i=1; i<=n; i++){
		cin>>WW[i];
		if (W[i]==WW[i]){
			good[i]=1;
			continue ;
		}
		for (int j=0; j<W[i].size(); j++) if (W[i][j]!=WW[i][j]) R[i]=j;
		for (int j=W[i].size()-1; ~j; j--) if (W[i][j]!=WW[i][j]) L[i]=j;
	}
	while (1){
		bool flag=1;
		char ch=0;
		for (int i=1; i<=n; i++) if (!good[i]){
			if (!L[i] || (ch && ch!=W[i][L[i]-1])){
				flag=0;
				break ;
			}
			ch=W[i][L[i]-1];
		}
		if (!flag) break ;
		for (int i=1; i<=n; i++) if (!good[i]) L[i]--;
	}
	while (1){
		bool flag=1;
		char ch=0;
		for (int i=1; i<=n; i++) if (!good[i]){
			if (R[i]+1==W[i].size() || (ch && ch!=W[i][R[i]+1])){
				flag=0;
				break ;
			}
			ch=W[i][R[i]+1];
		}
		if (!flag) break ;
		for (int i=1; i<=n; i++) if (!good[i]) R[i]++;
	}
	for (int i=1; i<=n; i++) if (!good[i]){
		for (int j=L[i]; j<=R[i]; j++) S+=W[i][j], T+=WW[i][j];
		break ;
	}
	for (int i=1; i<=n; i++){
		int tmp=KMP(S, W[i]);
		if (good[i]){
			if (tmp!=-1) kill("NO")
			continue ;
		}
		if (tmp!=R[i]) kill("NO")
		if (!KMP2(T, WW[i], R[i])) kill("NO")
	}
	cout<<"YES\n"<<S<<"\n"<<T<<"\n";
	
	return 0;
}