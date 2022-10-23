#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 1e5 + 10;
int cnt[100];

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
        cin >> s;
        int n = s.length();
        for (int i = 1; i <= 26; ++i) cnt[i] = 0;
        for (char c : s) cnt[c - 'a' + 1]++;
        int mn = n;
        for (int i = 1; i <= 26; ++i)
            if (cnt[i]) mn = min(cnt[i], mn);
        if (mn == n)
        {
            cout << s << "\n";
            continue;
        }
        if (mn == 1)
        {
            for (int i = 1; i <= 26; ++i)
                if (cnt[i] == 1)
                {
                    cout << (char)(i + 'a' - 1);
                    cnt[i]--;
                    break;
                }
            for (int i = 1; i <= 26; ++i)
                for (int j = 1; j <= cnt[i]; ++j) cout << (char)(i + 'a' - 1);
            cout << "\n";
            continue;
        }
        int f = 1;
        while (!cnt[f]) f++;
        cout << (char)(f + 'a' - 1);
        cnt[f]--;
        n--;
        if (cnt[f] > n - cnt[f] + 1)
        {
            int f2 = f + 1;
            while (!cnt[f2]) f2++;
            if (cnt[f] + cnt[f2] != n)
            {
                cout << (char)(f2 + 'a' - 1);
                cnt[f2]--;
                for (int i = 1; i <= cnt[f]; ++i) cout << (char)(f + 'a' - 1);
                cnt[f] = 0;
                int f3 = f2 + 1;
                while (!cnt[f3]) f3++;
                cout << (char)(f3 + 'a' - 1);
                cnt[f3]--;
            }
            for (int i = 1; i <= 26; ++i)
                if (i != f)
                for (int j = 1; j <= cnt[i]; ++j) cout << (char)(i + 'a' - 1);
            for (int i = 1; i <= cnt[f]; ++i) cout << (char)(f + 'a' - 1);
            cout << "\n";
        }
        else
        {
            string tmp;
            for (int i = 1; i <= 26; ++i)
                if (i != f)
                for (int j = 1; j <= cnt[i]; ++j) tmp += (char)(i + 'a' - 1);
            cout << (char)(f + 'a' - 1);
            cnt[f]--;
            for (char c : tmp)
            {
                cout << c;
                if (cnt[f]) cout << (char)(f + 'a' - 1), cnt[f]--;
            }
            cout << "\n";
        }
    }
    return 0;
}