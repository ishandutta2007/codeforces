#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

struct Problem {
    int a, t, id;
};

bool operator < (const Problem &a, const Problem &b) {
    if (a.a != b.a) {
        return a.a < b.a;
    }

    if (a.t != b.t) {
        return a.t < b.t;
    }

    return a.id < b.id;
}

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, t;
    cin >> n >> t;

    vector<Problem> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].a >> p[i].t;
        p[i].id = i;
    }

    sort(all(p));

    int cur = 0;
    int res = 0;
    set<pair<int, int>> setik;

    for (int i = n - 1; i >= 0; --i) {
        setik.insert({p[i].t, p[i].id});
        cur += p[i].t;

        while (sz(setik) > p[i].a || cur > t) {
            auto it = --setik.end();
            cur -= it->first;
            setik.erase(it);
        }   
 
        res = max(res, sz(setik));
    }

    setik.clear();
    cur = 0;


    cout << res << endl << res << endl;


    for (int i = n - 1; i >= 0; --i) {
        setik.insert({p[i].t, p[i].id});
        cur += p[i].t;

        while (sz(setik) > p[i].a || cur > t) {
            auto it = --setik.end();
            cur -= it->first;
            setik.erase(it);
        }   
 
        if (sz(setik) == res) {
            for (auto el : setik) {
                cout << el.second + 1 << " ";
            }
            cout << endl;
            return 0;
        }
    }


    return 0;
}