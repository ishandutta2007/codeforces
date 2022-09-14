#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int

vector <vector <int> > ans;

const int maxn = 110;
int pos[maxn];

vector <int> rebuild(vector <int> v, vector <int> op) {
    vector <int> res;

    int pos = (int)v.size() - 1;

    reverse(all(op));

    for (int d : op) {
        for (int i = pos - d + 1; i <= pos; i++) {
            res.push_back(v[i]);
        }

        pos -= d;
    }

    assert(pos == -1);
    return res;
}

void solve(vector <int> v) {
    for (int i = 0; i < (int)v.size(); i++) {
        pos[v[i]] = i;
    }
    int n = (int)v.size();

    for (int i = 0; i < n - 1; i++) {
        if (pos[i] < pos[i + 1]) {
            continue;
        }

        vector <int> op;
        int l = pos[i + 1];
        int r = pos[i];

        if (l > 0) {
            op.push_back(l);
        }

        int m = l;

        while (v[m] < v[m + 1]) {
            m++;
        }

        op.push_back(m - l + 1);
        op.push_back(r - m);
        if (r != n - 1) {
            op.push_back(n - 1 - r);
        }

        ans.push_back(op);
        v = rebuild(v, op);
        solve(v);
        break;
    }
}

int main() {
    vector <int> v;
    int n;
    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;
    }

    solve(v);

    cout << ans.size() << '\n';

    for (auto f : ans) {
        printf("%d ", f.size());
        for (int x : f) {
            printf("%d ", x);
        }

        printf("\n");
    }
}