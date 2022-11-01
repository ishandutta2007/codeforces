#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
const int M = 501;
const int INF = 2e9 + 10;
const int MOD = 1e9 + 7;

ll a[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    vector <int> nums;
    fr(i, n) {
        cin >> a[i];
        bool fnd = false;
        fr(j, nums.size())
            if (nums[j] == a[i])
                fnd = true;
        if (!fnd)
            nums.pb(a[i]);
        if (nums.size() >= 4) {
            cout << "NO";
            return 0;
        }
    }
    sort(nums.begin(), nums.end());
    if (nums.size() <= 2) {
        cout << "YES";
        return 0;
    }
    if (nums[2] - nums[1] == nums[1] - nums[0]) {
        cout << "YES";
    }
    else
        cout << "NO";



}