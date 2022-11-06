#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

ll n, i;

void brute() {
    vector<int> act, nxt;
    ll i, last, sol;

    act = {1, 5, 10, 50};
    last = 4;

    for (i = 2; i <= n && i <= 15; i++) {
        nxt.clear();
        for (auto e : act) {
            nxt.pb(e + 1);
            nxt.pb(e + 5);
            nxt.pb(e + 10);
            nxt.pb(e + 50);
        }

        act = nxt;
        sort(act.begin(), act.end());
        act.resize(unique(act.begin(), act.end()) - act.begin());

        //cerr << i << ' ' << act.size() << ' ' << act.size() - last << '\n';
        //last = act.size();
    }

    if (n <= 15) {
        sol = act.size();
    } else {
        sol = 1LL * act.size() + 49LL * (n - 15);
    }

    printf("%lld", sol);
    exit(0);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld", &n);
    brute();

    return 0;
}