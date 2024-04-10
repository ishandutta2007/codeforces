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
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans=inf, num, len;
int TR[MAXN*LOG][3], cnt;
vector<int> vec[MAXN*LOG];
stack<int> stk;

void add(){
	int node=0;
	while (!stk.empty()){
		if (!TR[node][stk.top()]){
			TR[node][stk.top()]=++cnt;
			TR[cnt][2]=TR[node][2]+1;
			//debug2(node, cnt)
		}
		node=TR[node][stk.top()];
		vec[node].pb(len);
		//cerr<<"add ";debug2(node, num)
		stk.pop();
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++){
		cin>>num;
		len=0;
		for (int x=num; x; x>>=1) len++, stk.push(x&1);
		vec[0].pb(len);
		add();
	}
	for (int i=0; i<=cnt; i++) if (vec[i].size()>=k){
		sort(all(vec[i]));
		int tmp=0;
		for (int j=0; j<k; j++) tmp+=vec[i][j];
		ans=min(ans, tmp-k*TR[i][2]);
	}
	cout<<ans<<'\n';
	
	return 0;
}