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

int n, m, k, u, v, x, y, t, a, b, c, ans;
int cnt[3];
string A[3], S;
vector<string> X, Y;

int Solve(){
	cin>>n>>A[0]>>A[1]>>A[2];
	S="";
	cnt[0]=cnt[1]=cnt[2]=0;
	X.clear();
	Y.clear();
	
	for (int i=0; i<3; i++){
		for (char ch:A[i]) cnt[i]+=ch-'0';
		if (cnt[i]>=n) X.pb(A[i]);
		if (cnt[i]<=n) Y.pb(A[i]);
	}
	if (X.size()>=2){
		int j=0;
		for (int i=0; i<2*n; i++){
			if (X[0][i]=='0') S+='0';
			else{
				while (j<2*n && X[1][j]=='0') S+='0', j++;
				S+='1';
				j++;
			}
		}
		while (j<2*n) S+=X[1][j++];
	}
	else{
		int j=0;
		for (int i=0; i<2*n; i++){
			if (Y[0][i]=='1') S+='1';
			else{
				while (j<2*n && Y[1][j]!='0') S+='1', j++;
				S+='0';
				j++;
			}
		}
		while (j<2*n) S+=Y[1][j++];
	}
	while (S.size()<3*n) S+='0';
	cout<<S<<"\n";
	
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
/*
1
3
011001
111010
010001

*/