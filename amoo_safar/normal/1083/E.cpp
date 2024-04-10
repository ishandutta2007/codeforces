#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
typedef long long ll;

const ll INF = LONG_LONG_MAX;

typedef pair < ll , ll > Line;
struct CHT{
    set < pair < Line , ll > > S;
    set < pair < ll , Line > > I;
    ll INF = 4e18;
    inline void Add(Line X)
    {
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
    inline ll GetMax(ll X)
    {
        auto it = I.upper_bound({X, {INF, INF}}); it --;
        return (X * it->second.first + it->second.second);
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

typedef pair<ll, ll> pll;
const ll MAXN = (ll) 1e6 + 10;

pair< pll, ll > rec[MAXN];
ll dp[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    CHT mx;
 
    ll n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> rec[i].F.F >> rec[i].F.S >> rec[i].S;
    
	sort(rec + 1, rec + 1 + n);
    //reverse(rec + 1, rec + 1 + n);
    
 	//dp[1] = rec[1].F.F * rec[1].F.S - rec[1].S;
 	//mx.Add( {-rec[1].F.F, dp[1]});
	mx.Add({0, 0});
	for(int i = 1; i <= n; i++){
	 	dp[i] = rec[i].F.F * rec[i].F.S - rec[i].S + mx.GetMax(rec[i].F.S);
	 	
		mx.Add({-rec[i].F.F, dp[i]});
	}
	//cerr << dp[1] << '\n';
 	
 	cout << *max_element(dp + 1, dp + 1 + n);
    return 0;
}