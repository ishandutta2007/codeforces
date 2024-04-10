#include <bits/stdc++.h>

#define lint long long int
using namespace std;

int len(lint n) {
    int ans = 0;
    while (n) {
        n /= 2;
        ++ ans;
    }

    return ans;
}

map <lint, lint> added;

void add(lint u, lint v, int w) {
    int lu = len(u), lv = len(v);
    while (u != v) {
        if (lu < lv) {
            added[v] += w;
            v /= 2;
            lv --;
        }
        else {
            added[u] += w;
            u /= 2;
            lu --;
        }
    }
}

lint query(lint u, lint v) {
    lint ans = 0;
    int lu = len(u), lv = len(v);
    while (u != v) {
        if (lu < lv) {
            ans += added[v];
            v /= 2;
            lv --;
        }
        else {
            ans += added[u];
            u /= 2;
            lu --;
        }
    }

    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    int q = 0;
    cin >> q;

    int type;
    lint u, v;
    int w;
    while (q --) {
        cin >> type >> u >> v;
        if (type == 1) {
            cin >> w;
            add(u, v, w);
        }
        else
            cout << query(u, v) << '\n';
    }

    return 0;
}