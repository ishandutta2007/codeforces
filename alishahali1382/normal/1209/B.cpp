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
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 1010, C=5*4*3*2;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN*C];
string s;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>s;
	for (int i=0; i<n; i++){
		cin>>a>>b;
		int cur=s[i]-'0';
		for (int tmp=0; tmp<b; tmp++) A[tmp]+=cur;
		for (; b<MAXN*C; b+=a){
			cur=1-cur;
			for (int tmp=b; tmp<b+a && tmp<MAXN*C; tmp++) A[tmp]+=cur;
		}
	}
	//for (int i=0; i<7; i++) cerr<<A[i]<<" \n"[i==6];
	for (int i=0; i<MAXN*C; i++) ans=max(ans, A[i]);
	kill(ans)
	
	return 0;
}