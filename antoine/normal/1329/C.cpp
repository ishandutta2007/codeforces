#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (1 << 20) + 9;
int a[MxN * 2 + 9];
int b[MxN * 2 + 9];
bool taken[(1 << 20) + 9];
vector<int> nums[MxN * 2 + 9];

void rem(int i) {
    for (;;) {
        const int l = i << 1;
        const int r = i << 1 | 1;
        if (!a[l] && !a[r]) {
            a[i] = 0;
            break;
        }
        if (a[l] > a[r]) {
            a[i] = a[l];
            i = l;
        } else {
            a[i] = a[r];
            i = r;
        }
    }
}

void f() {

    int h, g;
    cin >> h >> g;
    const int n = (1 << h) - 1;
    const int m = (1 << g) - 1;

    fill(a, a + 2 * n + 9, 0);
    fill(nums, nums + 2 * n + 9, vector<int>());

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        taken[a[i]] = false;
    }

    ll ans = 0;

    for (int i = n; i >= 1; --i) {
        nums[i] = move(nums[i << 1]);
        {
            vector<int> v = move(nums[i << 1 | 1]);
            nums[i].insert(nums[i].end(), v.begin(), v.end());
        }
        nums[i].push_back(a[i]);

        if (2 * i <= m) {
            const int th = max(b[i << 1], b[i << 1 | 1]);
            nums[i].erase(remove_if(nums[i].begin(), nums[i].end(), [th](const int x) {
                return x <= th;
            }), nums[i].end());
        }
        if (i <= m) {
            auto it = min_element(nums[i].begin(), nums[i].end());
            taken[*it] = true;
            b[i] = *it;
        }
    }

    cout << accumulate(b + 1, b + 1 + m, 0LL) << '\n';
    for (int i = n; i >= 1; --i) {
        assert(a[i]);
        if (taken[a[i]])
            continue;
        cout << i << ' ';
        rem(i);
        assert(!a[i] || taken[a[i]]);
    }
    cout << '\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)f();
    return 0;
}