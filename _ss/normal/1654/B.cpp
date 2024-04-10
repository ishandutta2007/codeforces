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
using vll = vector<ll>;

const int N = 1e5 + 10;

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        vi cnt(26, 0);
        cin >> s;
        for (char c : s) cnt[c - 'a']++;
        int i = 0;
        while (cnt[s[i] - 'a'] > 1)
        {
            cnt[s[i] - 'a']--;
            i++;
        }
        for (int j = i; j < (s.length()); ++j) cout << s[j];
        cout << "\n";
    }
    return 0;
}