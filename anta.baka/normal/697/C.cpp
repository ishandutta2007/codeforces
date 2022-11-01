#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
map<ll, ll> m;

void add(ll u, ll v, ll w) {
    while(u != v) {
        if(u < v)
            m[v] += w, v /= 2;
        else
            m[u] += w, u /= 2;
    }
}

ll get(ll u, ll v) {
    ll res = 0;
    while(u != v) {
        if(u < v)
            res += m[v], v /= 2;
        else
            res += m[u], u /= 2;
    }
    return res;
}

int main()
{
    int q;
    cin >> q;
    ll u, v, w;
    for(int i = 0, type; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> u >> v >> w;
            add(u, v, w);
        } else {
            cin >> u >> v;
            cout << get(u, v) << endl;
        }
    }
    return 0;
}