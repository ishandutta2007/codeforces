#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, l, r, sum;
vector<ll> v;
bool viv = false;


void solve() {
    cin >> n >> l >> r >> sum;
    l--, r--;
    int k = r - l + 1;
    sum -= k;

    v.resize(k);
    for (int i = 0; i < k; i++)
        v[i] = i;
    int msum = 0;
    for (auto i : v)
        msum += i;

    if (sum == msum) {
        set<int> left;
        for (int j = 0; j < n; j++)
            left.insert(j);
        for (auto i : v)
            left.erase(i);

        for (int j = 0; j < l; j++) {
            v.push_back(*(left.begin()));
            left.erase(left.begin());
        }
        reverse(v.begin(), v.end());
        for (auto i : left)
            v.push_back(i);

        for (auto &i : v)
            i++;
        for (auto i : v)
            cout << i << ' ';
        cout << '\n';
        return;        
    }

    for (int i = k - 1; i >= 0; i--) {
        for (int j = 0; j < n - k; j++) {
            v[i]++;
            msum++;
            if (msum == sum) {
                set<int> left;
                for (int j = 0; j < n; j++)
                    left.insert(j);
                for (auto i : v)
                    left.erase(i);

                for (int j = 0; j < l; j++) {
                    v.push_back(*(left.begin()));
                    left.erase(left.begin());
                }
                reverse(v.begin(), v.end());
                for (auto i : left)
                    v.push_back(i);

                for (auto &i : v)
                    i++;
                for (auto i : v)
                    cout << i << ' ';
                cout << '\n';
                return;
            }
        }
    }
    cout << "-1\n";
}

int main() {
    // viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1; 
    cin >> t;
    while (t--)
        solve();

    return 0;
}