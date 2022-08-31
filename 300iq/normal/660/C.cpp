#include <bits/stdc++.h>

using namespace std;

const int MAXN = 400000;

int pref[MAXN];
int a[MAXN];

int get(int l, int r) {
    if (l == 0) {
        return pref[r];
    } else {
        return pref[r] - pref[l - 1];
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    pref[0] = 1 - a[0];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + (1 - a[i]);
    }
    int len = 0;
    int left = 0, right = -1;
    for (int i = 0; i < n; i++) {
        int l = i; 
        int r = n;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (m < n && get(i, m) <= k) {
                l = m;
            } else {
                r = m;
            }
        }
        if (get(i, l) <= k) {
            if (l - i + 1 > len) {
                len = l - i + 1;
                left = i;
                right = l;
            }
        } 
    }
    for (int j = left; j <= right; j++) {
        a[j] = 1;
    }
    cout << len << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}