#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;

const int N = 1e5 + 10;

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        vi cnt(26);
        for (char c : s) cnt[c - 'a']++;
        for (int i = 1; i <= k; ++i)
        {
            bool check = true;
            for (int j = 0; j < min(26, n / k + 1); ++j)
                if (cnt[j] < i)
                {
                    cout << (char)('a' + j);
                    check = false;
                    break;
                }
            if (check) cout << (char)('a' + n / k);
        }
        cout << "\n";
    }
    return 0;
}