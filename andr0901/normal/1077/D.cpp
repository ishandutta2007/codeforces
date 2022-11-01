#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define ll long long

int n, k;

bool check(vector <int> nums, int m) {
    int ans = 0;
    forn (i, 0, 2e5 + 1)
        ans += nums[i] / m;
    return (ans >= k);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    vector <int> a(n);
    vector <int> nums(2e5 + 1, 0);
    forn (i, 0, n) {
        cin >> a[i];
        nums[a[i]]++;
    }
    int l = 1, r = 1e6;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (check(nums, m))
            l = m;
        else
            r = m;
    }
    int cnt = 0;
    forn (i, 0, 2e5 + 1) {
        while (nums[i] >= l) {
            if (cnt == k)
                return 0;
            cout << i << " ";
            nums[i] -= l;
            cnt++;
        }
    }
    return 0;
}