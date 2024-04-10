#include <bits/stdc++.h>

using namespace std;

vector <int> a;

int counter[100001];

int main() {
    int n, k, x;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x, a.push_back(x);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        counter[a[i]]++;
    for (int i = 1; i <= 100000; i++)
        cnt += (counter[i] != 0);
    if (cnt < k) {
        cout << -1 << " " << -1 << endl;
        return 0;
    }
    int l = 0;
    int r = n - 1;
    while (cnt >= k) {
        counter[a[r]]--;
        cnt -= (counter[a[r]] == 0);
        r--;
    }
    r++;
    counter[a[r]]++;
    cnt = k;
    while (cnt >= k) {
        counter[a[l]]--;
        cnt -= (counter[a[l]] == 0);
        l++;
    }
    l--;
    cout << l + 1 << " " << r + 1 << endl;
}