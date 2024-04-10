#include<bits/stdc++.h>

using namespace std;

int cnt(int l, int r) {
    if (r - l <= 1) return 0;
    int m = (r + l) / 2;
    return r - l - 1 + cnt(l, m) + cnt(m, r);
}

int const maxn = 1e5 + 5;
string s;
int ptr;
int a[maxn];
int b[maxn], in[maxn];
vector < int > g[maxn];

int check(int l, int r) {
    if (r - l <= 1) return 1;
    int m = (r + l) / 2;
    if (!check(l, m)) return 0;
    if (!check(m, r)) return 0;
    int cnt0 = m - l, cnt1 = r - m;
    while (cnt0 && cnt1) {
        if (ptr == (int)s.size()) return 0;
        if (s[ptr] == '0') cnt0--;
        else cnt1--;
        ptr++;
    }
    return 1;
}

void get(int l, int r) {
    if (r - l <= 1) return;
    int m = (r + l) / 2;
    get(l, m);
    get(m, r);
    int cnt0 = m - l, cnt1 = r - m;
    int cur0 = 0, cur1 = 0;
    int now = l;
    while (cnt0 && cnt1) {
        if (s[ptr] == '0') {
            g[a[l + cur0]].push_back(a[m + cur1]);
            in[a[m + cur1]]++;
            cnt0--;
            b[now] = a[l + cur0];
            cur0++;
        }
        else {
            g[a[m + cur1]].push_back(a[l + cur0]);
            in[a[l + cur0]]++;
            cnt1--;
            b[now] = a[m + cur1];
            cur1++;
        }
        now++;
        ptr++;
    }
    while (cnt0) {
        b[now] = a[l + cur0];
        cur0++;
        cnt0--;
        now++;
    }
    while (cnt1) {
        b[now] = a[m + cur1];
        cur1++;
        cnt1--;
        now++;
    }
    for (int j = l; j < r; ++j) a[j] = b[j];
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    int lef = 0, righ = 100001;
    while (righ - lef > 1) {
        int mid = (righ + lef) / 2;
        if (cnt(0, mid) < (int)s.size()) lef = mid;
        else righ = mid;
    }
    vector < int > interes;
    for (int i = 0; i < 19; ++i) interes.push_back((1 << i));
    int L = righ, R = 100001;
    while (R - L > 1) {
        int M = (R + L) / 2;
        ptr = 0;
        if (check(0, M) && ptr < (int)s.size()) L = M;
        else R = M;
    }
    for (int n = L; n <= 100000; ++n) interes.push_back(n);
    for (auto n : interes) {
        ptr = 0;
        if (check(0, n) && ptr == (int)s.size()) {
            cout << n << '\n';
            for (int i = 0; i < n; ++i) a[i] = i;
            ptr = 0;
            get(0, n);
            vector < int > now;
            for (int i = 0; i < n; ++i) if (in[i] == 0) now.push_back(i);
            int head = 0;
            int f = 1;
            while (head < (int)now.size()) {
                a[now[head]] = f;
                f++;
                for (auto key : g[now[head]]) {
                    in[key]--;
                    if (in[key] == 0) now.push_back(key);
                }
                head++;
            }
            for (int i = 0; i < n; ++i) cout << a[i] << " ";
            exit(0);
        }
    }
    return 0;
}