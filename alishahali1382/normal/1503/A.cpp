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
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
string S, X, Y;

bool check(string &S){
	int ted=0;
	for (char ch:S){
		if (ch=='(') ted++;
		else ted--;
		if (ted<0) return 0;
	}
	return (ted==0);
}

int Solve(){
	cin>>n>>S;
	X=Y=S;
	char ch='(';
	int ted=0;
	for (int i=0; i<n; i++) if (S[i]=='1') ted++;
	if (ted&1) kill("NO")
	ted>>=1;
	for (int i=0; i<n; i++){
		if (S[i]=='1'){
			if (ted){
				X[i]=Y[i]='(';
				ted--;
			}
			else{
				X[i]=Y[i]=')';
			}
		}
		else{
			X[i]=ch;
			ch='('+')'-ch;
			Y[i]=ch;
		}
	}
	if (check(X) && check(Y)){
		cout<<"YES\n"<<X<<"\n"<<Y<<"\n";
		return 0;
	}
	kill("NO")
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}