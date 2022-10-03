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
const int MAXN = 200010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, last;
unordered_map<int, int> par;
unordered_map<int, int> xo;

pii get(int x){
	if (!par.count(x) || par[x]==x) return {par[x]=x, 0};
	pii p=get(par[x]);
	return {par[x]=p.first, xo[x]^=p.second};
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>m;
	while (m--){
		cin>>t>>u>>v;
		u^=last;
		v^=last;
		if (u>v) swap(u, v);
		v++;
		pii p=get(u), q=get(v);
		int tmp=p.second^q.second;
		if (t==1){
			cin>>x;
			x^=last;
			if (p.first==q.first) continue ;
			par[p.first]=q.first;
			xo[p.first]=x^tmp;
			continue ;
		}
		if (p.first==q.first) cout<<(last=tmp)<<'\n';
		else{
			last=1;
			cout<<"-1\n";
		}
	}
	
	
	return 0;
}