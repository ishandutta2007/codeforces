#include <bits/stdc++.h>

#define int long long
#define ll long long
#define vc vector<char>
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define si set<ll>
#define pii pair<int,int>
#define pbi pair<bool,int>
#define SORT(c) sort(c.begin(),c.end())
#define SORTC(c, cmp) sort(c.begin(),c.end(),cmp)
#define mapii map<int,int>
#define mapll map<ll,ll>
#define pb push_back
#define F first
#define S second

using namespace std;

int32_t main() {
    int T{1};
    while (T--) {
        int n{};
        cin >> n;

        vi a(n, 0);

        mapii suffix{}, prefix{};

        for (int i = 0; i < n; ++i) {
            cin >> a[i];

            if (!i) {
                prefix[i] = INT64_MAX;
            }
            else {
                prefix[i] = prefix[i - 1] & ~a[i - 1];
            }

        }

        for (int j = n - 1; j >= 0; --j) {
            if (j == n - 1) {
                suffix[j] = INT64_MAX;
            }
            else {
                suffix[j] = suffix[j + 1] & ~a[j + 1];
            }
        }

        int mx{};
        int pos{};
        for (int k = 0; k < n; ++k) {
            int val{};
            val = prefix[k] & a[k] & suffix[k];

            if (val > mx) {
                mx = val;
                pos = k;
            }
        }

        cout << a[pos] << " ";
        for (int l = 0; l < n; ++l) {
            if (l == pos) continue;

            cout << a[l] << " ";
        }
    }

}