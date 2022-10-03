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
const int MAXN = 100010, LOG=18, SZ=400;

int n, m, k, u, v, x, s, t, a, b, ans;
int TR[MAXN*SZ][3], N;
vector<int> D[MAXN];

void add(int node, int num){
	TR[node][2]=min(TR[node][2], num);
	for (int i=LOG-1; i>=0; i--){
		int c=(num>>i)&1;
		if (!TR[node][c]) TR[TR[node][c]=++N][2]=inf;
		node=TR[node][c];
		TR[node][2]=min(TR[node][2], num);
	}
}

int get(int node, int x, int lim){
	int res=0;
	for (int i=LOG-1; i>=0; i--){
		int c=(x>>i)&1;
		if (TR[node][c^1] && TR[TR[node][c^1]][2]<=lim){
			node=TR[node][c^1];
			res|=(1<<i);
		}
		else node=TR[node][c];
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=1; i<MAXN; i++) for (int j=i; j<MAXN; j+=i) D[j].pb(i);
	for (int i=1; i<MAXN; i++) TR[++N][2]=inf;
	cin>>n;
	while (n--){
		cin>>t;
		if (t==1){
			cin>>x;
			for (int d:D[x]) add(d, x);
			continue ;
		}
		cin>>x>>k>>s;
		if (x%k || TR[k][2]>s-x) cout<<"-1\n";
		else cout<<(x^get(k, x, s-x))<<'\n';
	}
	
	
	return 0;
}