#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll , ll> pll;

#define endl '\n'
#define X first
#define Y second

const ll MAXN = 1e6 + 10;

ll n , m , s , t , ds , dt , par[MAXN] , sz[MAXN] , cnt[MAXN];
vector<ll> adj[MAXN];
vector<pll> E , ST;

ll Find(ll v){
    return (par[v] == -1 ? v : par[v] = Find(par[v]));
}

void Union(ll v , ll u){
    v = Find(v) ; u = Find(u);
    if(u == v)  return;
    if(sz[v] < sz[u])   swap(v , u);
    par[u] = v;
    sz[v] += sz[u];
}

int main(){
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0);
    fill(par , par + MAXN , -1);
    fill(sz , sz + MAXN , 1);

    cin >> n >> m;
    for(ll i = 0 ; i < m ; i++){
        ll v , u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
        E.push_back({v , u});
    }
    cin >> s >> t >> ds >> dt;

    for(pll i : E){
        ll v = i.X , u = i.Y;
        if(v == s || v == t || u == s || u == t)    continue;
        if(Find(v) != Find(u)){
            Union(v , u);
            ST.push_back({v , u});
        }
    }

    for(ll i : adj[s])  cnt[Find(i)] = 1;
    for(ll i : adj[t])  cnt[Find(i)] = (cnt[Find(i)] == 1 ? 2 : 0);

    ll ind = (max_element(cnt , cnt + MAXN) - cnt);
    if(cnt[ind] == 2){
        ll A = 0 , B = 0;
        for(ll i : adj[s]){
            if(Find(i) == ind){
                A = i;
                ds--;
                ST.push_back({i , s});
                break;
            }
        }

        for(ll i : adj[t]){
            if(Find(i) == ind){
                B = i;
                dt--;
                ST.push_back({i , t});
                break;
            }
        }
        Union(A , s);
        Union(B , t);
    }

    for(ll i : adj[s]){
        if(i == t && Find(s) != Find(t)){
            Union(s , t);
            ds--;
            dt--;
            ST.push_back({t , s});
        }
    }

    fill(cnt , cnt + MAXN , 0);

    for(ll i : adj[s])  cnt[Find(i)] = 1;
    for(ll i : adj[t])  cnt[Find(i)] = (cnt[Find(i)] == 1 ? 2 : 0);

    for(ll i : adj[s]){
        if(ds == 0) break;
        if(cnt[Find(i)] == 2)   continue;
        if(Find(i) != Find(s)){
            Union(i , s);
            ds--;
            ST.push_back({i , s});
        }
    }

    for(ll i : adj[t]){
        if(dt == 0) break;
        if(Find(i) != Find(t)){
            Union(i , t);
            dt--;
            ST.push_back({i , t});
        }
    }

    for(ll i : adj[s]){
        if(ds == 0) break;
        if(Find(i) != Find(s)){
            Union(i , s);
            ds--;
            ST.push_back({i , s});
        }
    }

    if(ST.size() != n - 1)  return cout << "No" << endl , 0;
    cout << "Yes" << endl;
    for(pll i : ST) cout << i.X << " " << i.Y << endl;
}
/*
3 3
1 2
2 3
3 1
1 2 1 1


7 8
7 4
1 3
5 4
5 7
3 2
2 4
6 1
1 2
6 4 1 4

5 5
1 3
1 4
1 5
2 3
2 4
1 2 2 2
*/