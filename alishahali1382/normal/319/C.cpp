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
    ll INF = 4e18;
    inline void Add(Line X){
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
    inline ll GetMin(ll X){
        auto it = I.upper_bound({X, {INF, INF}}); it --;
        return -(X * it->second.first + it->second.second);
    }
    inline ll Intersection(Line X, Line Y){
        if (X.first == Y.first && X.second <= Y.second)
            return (-INF);
        if (X.first == Y.first)
            return (INF);
        return ((X.second - Y.second) / (Y.first - X.first)) + ((X.second - Y.second) % (Y.first - X.first) > 0);
    }
    
} cht;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
int B[MAXN];
ll dp[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=n; i++) cin>>B[i];
	cht.Add({B[1], dp[1]=0});
	for (int i=2; i<=n; i++){
		dp[i]=cht.GetMin(A[i]);
		cht.Add({B[i], dp[i]});
	}
	cout<<dp[n]<<endl;
	
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