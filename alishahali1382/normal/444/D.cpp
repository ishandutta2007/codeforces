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
#define kill(x) return cout<<(x)<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
map<string, vector<int>> mp;
map<pair<string, string>, int> ANS;
string S, A, B;

int Calc(vector<int> &A, vector<int> &B, int sa, int sb){
	int res=n+1;
	for (int a:A){
		if (B.back()>=a){
			int b=*lower_bound(all(B), a);
			res=min(res, b-a+sb);
		}
		if (B[0]<a){
			int b=*--upper_bound(all(B), a);
			res=min(res, a-b+sa);
		}
	}
	return res;
}

int Solve(){
	cin>>A>>B;
	if (!mp.count(A) || !mp.count(B)) kill(-1)
	if (A.size()>B.size()) swap(A, B);
	for (int i=0; i+A.size()<=B.size(); i++) if (B.substr(i, A.size())==A) kill(B.size())
	if (A>B) swap(A, B);
	if (mp[A].size()>mp[B].size()) swap(A, B);
	if (ANS.count({A, B})) kill((ANS[{A, B}]))
	kill((ANS[{A, B}]=Calc(mp[A], mp[B], A.size(), B.size())));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>S>>m;
	n=S.size();
	for (int j=1; j<=4; j++) for (int i=0; i+j<=n; i++) mp[S.substr(i, j)].pb(i);
	while (m--) Solve();
	
	return 0;
}