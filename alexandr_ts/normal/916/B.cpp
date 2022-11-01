#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 100;
const int N = 1e6 + 10;

int main() {
    //freopen("a.in", "r", stdin);
    ll n, k;
    cin >> n >> k;
    ll k1 = k;
    vector <ll> nums;
    int bits = 0;
    for (int i = 0; i < M; i++)
        nums.pb(0);
    while (n) {
        nums.pb(n % 2);
        bits += (n % 2);
        n /= 2;

    }
    if (bits > k) {
        cout << "No";
        return 0;
    }

    k -= bits;

    while (nums.size() < 2 * M)
        nums.pb(0);

    for (int i = 2 * M - 1; i >= 0; i--) {
        if (nums[i] && nums[i] <= k) {
            k -= nums[i];
            nums[i - 1] += 2 * nums[i];
            nums[i] = 0;
        }
        else if (nums[i] > k) break;
    }



    vector <int> ans;

    if (k) {
        for (int i = 0; i < 2 * M; i++)
            if (nums[i]) {
                nums[i]--;
                k--;
                for (int j = i - 1; j >= i - k - 1; j--)
                    ans.pb(j);
                ans.pb(i - k - 1);

                for (int j = i; j < 2 * M; j++)
                    for (int j1 = 0; j1 < nums[j]; j1++)
                        ans.pb(j);
                sort(ans.begin(), ans.end());
                reverse(ans.begin(),ans.end());
                assert((int)ans.size() == k1);
                cout << "Yes\n";
                for (auto t: ans)
                    cout << t - M << " ";
                return 0;
            }
    }

    cout << "Yes\n";
    assert(accumulate(nums.begin(), nums.end(), 0ll) == k1);
    for (int i = 2 * M - 1; i >= 0; i--)
        for (int j = 0; j < nums[i]; j++)
            cout << i - M << " ";

}