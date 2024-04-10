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
#include <complex>
#include <bitset>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;

mt19937 rr(random_device{}());

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

struct Person {
    int type;
    int pos; 
    int t;
    int id;
};


bool operator < (const Person &a, const Person &b) {
    if (a.pos - a.t != b.pos - b.t) 
        return a.pos - a.t < b.pos - b.t;
    if (a.type != b.type)
        return a.type > b.type;
    return (a.type == 1 ? a.pos < b.pos : a.pos > b.pos);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");
    
    int n, x, y;
    cin >> n >> x >> y;
    vector<Person> h(n);
    for (int i = 0; i < n; ++i) {
        int g, p, t;
        cin >> g >> p >> t;
        h[i] = {g, p, t, i};
    }

    vector<pair<int, int>> ans(n);
    sort(all(h));

    // for (int i = 0; i < n; ++i) {
    //     cout << h[i].pos - h[i].t << " ";
    // }
    // cout << endl;
    for (int i = 0; i < n; ) {
        int j = i;
        vector<pair<int, int>> u, v;
        for (; j < n && h[i].pos - h[i].t == h[j].pos - h[j].t; ++j) {
            if (h[j].type == 1) {
                u.push_back({h[j].pos, y});
            } else {
                v.push_back({x, h[j].pos});
            }
        }
        // cout << i << " " << j << endl;
        for (auto el : v) {
            u.push_back(el);
        }

        for (int k = i; k < j; ++k)
            ans[h[k].id] = u[k - i];
        i = j;
    }

    for (int i = 0; i < n; ++i)
        cout << ans[i].first << " " << ans[i].second << "\n";

}