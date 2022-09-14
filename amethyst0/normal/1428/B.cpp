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

const int maxn = (int)3e5 + 10;
char s[maxn];
vector <int> ed[maxn];
vector <int> red[maxn];
bool used[maxn];

vector <int> ord;

int dfs(int v) {
    if (used[v]) {
        return 0;
    }

    used[v] = true;

    int ans = 1;

    for (int x : ed[v]) {
        ans += dfs(x);
    }

    ord.push_back(v);
    return ans;
}

int rdfs(int v) {
    if (used[v]) {
        return 0;
    }

    used[v] = true;
    int ans = 1;

    for (int x : red[v]) {
        ans += rdfs(x);
    }

    return ans;
}

int main() {
    int t;

    cin >> t;

    while (t--) {
        int n;
        scanf("%d", &n);
        scanf("%s", s);

        for (int i = 0; i < n; i++) {
            ed[i].clear();
            red[i].clear();
            used[i] = false;
        }

        for (int j = 0; j < n; j++) {
            int nx = (j + 1) % n;
            if (s[j] == '>') {
                ed[j].push_back(nx);
                red[nx].push_back(j);
            }
            else if (s[j] == '<') {
                ed[nx].push_back(j);
                red[j].push_back(nx);
            }
            else {
                ed[j].push_back(nx);
                ed[nx].push_back(j);
                red[j].push_back(nx);
                red[nx].push_back(j);
            }
        }

        ord.clear();

        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                dfs(i);
            }
        }

        for (int i = 0; i < n; i++) {
            used[i] = false;
        }

        int v = ord.back();

        if (rdfs(v) == n) {
            printf("%d\n", n);
            continue;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int pre = i - 1;
            if (pre < 0) {
                pre = n - 1;
            }
            if (s[i] == '-' || s[pre] == '-') {
                ans++;
            }
        }

        printf("%d\n", ans);
    }
}