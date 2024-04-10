#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<pii, ll> piii;
typedef pair<ll, ll> Line;
#define debug(x) cerr<<#x<<'='<<x<<endl;
#define debugp(x) cerr<<#x<<"= {"<<x.first<<", "<<x.second<<"}"<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000010LL;
const int mod = 1000000007;
const int MAXN = 1000010;

struct CHT
{
    typedef pair < ll , ll > Line;
    vector < pair < ll , Line > > A;
    ll INF = 4e18;
    inline void Add(Line X)
    {
        while ((int)A.size() && Intersection(A.back().second, X) <= A.back().first)
            A.pop_back();
        if (A.size())
            A.push_back({Intersection(A.back().second, X), X});
        else
            A.push_back({-INF, X});
    }
    inline ll GetMax(ll X)
    {
        int lb = upper_bound(A.begin(), A.end(), pair < ll , Line > {X, {INF, INF}}) - A.begin() - 1;
        return (X * A[lb].second.first + A[lb].second.second);
    }
    inline ll Intersection(Line X, Line Y)
    {
        if (X.first == Y.first && X.second <= Y.second)
            return (-INF);
        if (X.first == Y.first)
            return (INF);
        return ((X.second - Y.second) / (Y.first - X.first)) + ((X.second - Y.second) % (Y.first - X.first) > 0);
    }
};

ll n, m, u, v, x, y, t, a, b, ans;
piii A[MAXN];
ll dp[MAXN];
CHT cht;

bool cmp(piii i, piii j){return i.first.first<j.first.first;}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>x>>y>>a;
		A[i]={{x, y}, a};
	}
	sort(A+1, A+n+1, cmp);
	cht.Add({0, 0});
	for (int i=1; i<=n; i++){
		ll x=A[i].first.first, y=A[i].first.second, a=A[i].second; 
		dp[i]=x*y-a+cht.GetMax(-y);
		cht.Add({x, dp[i]});
		ans=max(ans, dp[i]);
	}
	cout<<ans<<endl;
	
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