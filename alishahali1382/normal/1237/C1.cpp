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
const int MAXN = 50010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int X[MAXN], Y[MAXN], Z[MAXN];
int ind[MAXN];
map<int, vector<int>> mp;
map<int, map<int, vector<int>>> shit;
vector<int> vec;
set<int> st;

bool cmp(int i, int j){
	if (X[i]!=X[j]) return X[i]<X[j];
	if (Y[i]!=Y[j]) return Y[i]<Y[j];
	return Z[i]<Z[j];
}

void fuck(vector<int> &F){
	while (F.size()>=2){
		sort(all(F), cmp);
		int x=F.back();
		F.pop_back();
		int y=F.back();
		F.pop_back();
		cout<<x<<' '<<y<<'\n';
		st.erase(x);
		st.erase(y);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>X[i]>>Y[i]>>Z[i], shit[X[i]][Y[i]].pb(i), st.insert(i);
	for (auto it:shit) for (auto itt:it.second) fuck(itt.second);
	for (int i:st) mp[X[i]].pb(i);
	for (auto it:mp) fuck(it.second);
	for (int i:st) vec.pb(i);
	sort(all(vec), cmp);
	fuck(vec);
	
	
	return 0;
}
/*
4
2 2 2
3 2 2
2 3 2
2 2 3

*/