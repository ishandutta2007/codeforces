#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int a[N], b[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> nums;
    nums.reserve(2 * N);
    unordered_map <int, int> a1, b1;
    fr(i, n) {
        cin >> a[i];
        a1[a[i]]++;
        nums.pb(a[i]);
    }
    fr(i, m) {
        cin >> b[i];
        b1[b[i]]++;
        nums.pb(b[i]);
    }
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    reverse(nums.begin(), nums.end());
    int cnt1 = 0, cnt2 = 0;
    fr(i, nums.size()) {
        if (a1.count(nums[i]))
            cnt1 += a1[nums[i]];
        if (b1.count(nums[i]))
            cnt2 += b1[nums[i]];
        if (cnt1 > cnt2) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}