#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5;
string a[maxn];
int s[2][maxn];
set < int > top;

void add(int t, int l, int x) {
    while (l < maxn) {
        s[t][l] += x;
        l = (l|(l + 1));
    }
}

int get(int t, int l) {
    int ans = 0;
    while (l >= 0) {
        ans += s[t][l];
        l = (l&(l + 1)) - 1;
    }
    return ans;
}

void get(int n) {
    int pos = (*top.rbegin());
    int l = pos + 1, r = n + 2;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (get(0, mid) - get(0, pos) == 0 && get(1, mid) - get(1, pos) == 0) l = mid;
        else r = mid;
    }
    cout << a[l] << '\n';
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    a[0] = "unlock";
    a[1] = "blue";
    for (int i = 2; i <= n + 1; ++i) cin >> a[i];
    for (int i = 0; i <= n + 1; ++i) {
        if (a[i] == "lock") add(0, i, 1);
        else if (a[i] == "unlock") add(1, i, 1);
    }
    for (int i = 0; i <= n; ++i) {
        if (a[i] == "unlock" && a[i + 1] != "lock" && a[i + 1] != "unlock") top.insert(i);
    }
    get(n);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int pos;
        cin >> pos;
        pos++;
        if (a[pos] == "unlock") {
            add(1, pos, -1);
            if (pos != n + 1 && a[pos + 1] != "lock" && a[pos + 1] != "unlock") {
                top.erase(pos);
            }
        }
        else if (a[pos] == "lock") {
            add(0, pos, -1);
        }
        else {
            if (a[pos - 1] == "unlock") top.erase(pos - 1);
        }
        cin >> a[pos];
        if (a[pos] == "unlock") {
            add(1, pos, 1);
            if (pos != n + 1 && a[pos + 1] != "lock" && a[pos + 1] != "unlock") {
                top.insert(pos);
            }
        }
        else if (a[pos] == "lock") {
            add(0, pos, 1);
        }
        else {
            if (a[pos - 1] == "unlock") top.insert(pos - 1);
        }
        get(n);
    }
    return 0;
}