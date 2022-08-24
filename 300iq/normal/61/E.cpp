#include <bits/stdc++.h>
#define fc first
#define sc second
#define mp make_pair
#define int long long

using namespace std;

int t[10000000];
int tt[10000000];

const int MAXN = 10000000;

void inc(int p, int x) {
    for (; p < MAXN; p += (p & -p)) {
        t[p] += x;
    }
}

int get(int p) {
    int res = 0;
    for (; p > 0; p -= (p & -p)) {
        res += t[p];
    }
    return res;
}

void inc_t(int p, int x) {
    for (; p < MAXN; p += (p & -p)) {
        tt[p] += x;
    }
}

int get_t(int p) {
    int res = 0;
    for (; p > 0; p -= (p & -p)) {
        res += tt[p];
    }
    return res;
}


main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> srt;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        srt.push_back(a[i]);
    }
    sort(srt.begin(), srt.end());
    srt.resize(unique(srt.begin(), srt.end()) - srt.begin());
    reverse(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(srt.begin(), srt.end(), a[i]) - srt.begin();
    }
    for (int i = 0; i < n; i++) {
        int last = get(a[i]);
        inc(a[i] + 1, 1);
        inc_t(a[i] + 1, last);
        ans += get_t(a[i]);
    }
    cout << ans << endl;
}