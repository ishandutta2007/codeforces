#include <bits/stdc++.h>

#define fc first
#define sc second
#define all(x) x.begin(), x.end()
#define bit(x) __builtin_popcount(x)
#define pb push_back
#define popb pop_back
#define ll long long

using namespace std;

int n, m;
vector <int> a, b, pa;
vector <int> add;

bool check(int x) {
    b.assign(m, 0);
    a = pa;
    for (int i = 0; i < n; i++) {
        if (a[i] < m) b[a[i]]++;
    }
    while (1) {
        int mn = INT_MAX;
        int ind = -1;
        for (int i = 0; i < m; i++) if (b[i] < mn) {
            mn = b[i];
            ind = i;
        }
        if (b[ind] >= x) return 1;
        bool good = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] >= m) {
                good = 1; 
                a[i] = ind;
                break;
            }
        }
        if (good) b[ind]++;
        else {
            int need = ind;
            int mx = INT_MIN;
            ind = -1;
            for (int i = 0; i < m; i++) if (b[i] > mx) {
                mx = b[i];
                ind = i;
            }
            if (mx <= x) return 0; 
            else {
                b[ind]--;
                b[need]++;
                for (int i = 0; i < n; i++) {
                    if (a[i] == ind) {
                        a[i] = need;
                        break;
                    }
                }
            }
        }
    }
}

vector <int> ret(int x) {
    b.assign(m, 0);
    a = pa;
    for (int i = 0; i < n; i++) {
        if (a[i] < m) b[a[i]]++;
    }
    while (1) {
        int mn = INT_MAX;
        int ind = -1;
        for (int i = 0; i < m; i++) if (b[i] < mn) {
            mn = b[i];
            ind = i;
        }
        if (b[ind] >= x) break;
        bool good = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] >= m) {
                good = 1; 
                a[i] = ind;
                break;
            }
        }
        if (good) b[ind]++;
        else {
            int need = ind;
            int mx = INT_MIN;
            ind = -1;
            for (int i = 0; i < m; i++) if (b[i] > mx) {
                mx = b[i];
                ind = i;
            }
            if (mx <= x) assert(0);
            else {
                b[ind]--;
                b[need]++;
                for (int i = 0; i < n; i++) {
                    if (a[i] == ind) {
                        a[i] = need;
                        break;
                    }
                }
            }
        }
    }
    return a;
}

int main() {
    scanf("%d%d", &n, &m);
    a.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), a[i]--;
    pa = a;
    int l = 0, r = n + 1;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    a = ret(l);
    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += (pa[i] != a[i]);
    printf("%d %d\n", l, cnt);
    for (auto c : a) {
        printf("%d ", c + 1);
    }
    puts("");
}