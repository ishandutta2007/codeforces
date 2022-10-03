#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<x<<endl;
#define debugp(x) cerr<<#x<<"= {"<<x.first<<", "<<x.second<<"}"<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010;

struct CHT{
    typedef pair < ll , ll > Line;
	set < pair < Line , ll > > S;
    set < pair < ll , Line > > I;
    vector<Line> lines;
    ll INF = 4e18;
    inline void Add(Line X)
    {
    	lines.pb(X);
        X={-X.first, -X.second};
		ll t = -INF;
        auto it = S.lower_bound({X, -INF});
        while ((int)S.size())
        {
            if (it == S.begin())
                {t = -INF; break;}
            it --; ll r = Intersection(it->first, X);
            if (r <= it->second)
                I.erase({it->second, it->first}), it = S.erase(it);
            else
                {t = r; break;}
        }
        it = S.lower_bound({X, -INF});
        while ((int)S.size())
        {
            if (it == S.end())
                break;
            ll r = Intersection(X, it->first);
            Line Y = it->first;
            I.erase({it->second, it->first});
            it = S.erase(it);
            if (r <= t)
            {
                r = -INF;
                if (it != S.begin())
                    it --, r = Intersection(it->first, Y);
                S.insert({Y, r}); I.insert({r, Y}); return ;
            }
            if (it != S.end() && it->second <= r)
                continue;
            S.insert({Y, r}); I.insert({r, Y}); break;
        }
        S.insert({X, t}); I.insert({t, X});
    }
    inline ll GetMin(ll X)
    {
        auto it = I.upper_bound({X, {INF, INF}}); it --;
        return -(X * it->second.first + it->second.second);
    }
    inline ll Intersection(Line X, Line Y)
    {
        if (X.first == Y.first && X.second <= Y.second)
            return (-INF);
        if (X.first == Y.first)
            return (INF);
        return ((X.second - Y.second) / (Y.first - X.first)) + ((X.second - Y.second) % (Y.first - X.first) > 0);
    }
    inline int getsize(){return lines.size();}
    inline void merg(CHT ch){
    	for (Line l:ch.lines) Add(l);
    	ch.I.clear();
    	ch.S.clear();
    	ch.lines.clear();
	}
} cht[MAXN];

int n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN];
ll B[MAXN];
ll dp[MAXN];
int id[MAXN];
vector<int> G[MAXN];

void dfs(int node, int par){
	dp[node]=INF;
	id[node]=node;
	int x=0;
	for (int v:G[node]) if (v!=par){
		dfs(v, node);
		if (cht[id[v]].getsize()>x){
			x=cht[id[v]].getsize();
			id[node]=id[v];
		}
	}
	if (G[node].size()==1 && node!=1) dp[node]=0;
	else{
		for (int v:G[node]) if (v!=par && id[v]!=id[node]) cht[id[node]].merg(cht[id[v]]);
		dp[node]=cht[id[node]].GetMin(A[node]);
	}
	cht[id[node]].Add({B[node], dp[node]});
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=n; i++) cin>>B[i];
	for (int i=0; i<n-1; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1, 0);
	for (int i=1; i<=n; i++) cout<<dp[i]<<' ';cout<<endl;
	
	return 0;
}
/*
          .---.                                                                     .---.              ...-'  |`. ..-'''-.       / .--. \        .-''-.
          |   |.--.                       .                     .                   |   |.--.          |      |  |\.-'''\ \     ' '    ' '     .' .-.  )
          |   ||__|                     .'|                   .'|                   |   ||__|          ....   |  |       | |    \ \    / /    / .'  / /
          |   |.--.                    <  |                  <  |                   |   |.--.            -|   |  |    __/ /      `.`'--.'    (_/   / /
    __    |   ||  |                     | |             __    | |             __    |   ||  |             |   |  |   |_  '.      / `'-. `.        / /
 .:--.'.  |   ||  |                 _   | | .'''-.   .:--.'.  | | .'''-.   .:--.'.  |   ||  |          ...'   `--'      `.  \   ' /    `. \      / /
/ |   \ | |   ||  |               .' |  | |/.'''. \ / |   \ | | |/.'''. \ / |   \ | |   ||  |          |         |`.      \ '. / /       \ '    . '
`" __ | | |   ||  |              .   | /|  /    | | `" __ | | |  /    | | `" __ | | |   ||  |          ` --------\ |       , || |         | |  / /    _.-')
 .'.''| | |   ||__|            .'.'| |//| |     | |  .'.''| | | |     | |  .'.''| | |   ||__|           `---------'        | || |         | |.' '  _.'.-''
/ /   | |_'---'              .'.'.-'  / | |     | | / /   | |_| |     | | / /   | |_'---'                                 / ,' \ \       / //  /.-'_.'
\ \._,\ '/                   .'   \_.'  | '.    | '.\ \._,\ '/| '.    | '.\ \._,\ '/                              -....--'  /   `.'-...-'.'/    _.'
 `--'  `"                               '---'   '---'`--'  `" '---'   '---'`--'  `"                               `.. __..-'       `-...-'( _.-'
*/