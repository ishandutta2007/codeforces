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
const int mod=1000000007;
const int MAXN=5010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int G[MAXN], mark[MAXN*3];
int A[MAXN];
string S;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=3; i<MAXN; i++){
		for (int j=2; j<i; j++) mark[G[j-1]^G[i-j]]=i;
		while (mark[G[i]]==i) G[i]++;
	}
	cin>>S;
	n=S.size();
	for (int i=1; i+1<n; i++) A[i]=(S[i-1]==S[i+1]);
	for (int i=0; i+1<n; i++) if (!A[i]){
		int sz=1;
		while (A[i+sz]) sz++;
		ans^=G[sz+1];
	}
	if (!ans) kill("Second")
	cout<<"First\n";
	for (int i=0; i+1<n; i++) if (!A[i]){
		int sz=1;
		while (A[i+sz]) sz++;
		for (int j=1; j<sz; j++) if ((G[j]^G[sz-j]^G[sz+1]^ans)==0){
			cout<<i+j+1<<'\n';
			return 0;
		}
	}
	
	return 0;
}