#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 3e5 + 20;
const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int n =s.size();
    int sum = 0;
    fr(i, s.size())
        sum += (s[i] - '0');
    sum %= 3;
    if (sum == 0) {
        cout << s;
        return 0;
    }
    if (sum == 1) {
        string ans1;
        for (int j = n - 1; j >= 0; j--)
            if ((s[j] - '0') % 3 == 1) {
                ans1 = s;
                ans1.erase(j, 1);
                int cnt = 0;
                while (cnt < ans1.size() && ans1[cnt] == '0')
                    cnt++;
                ans1.erase(0, min((int)ans1.size() - 1, cnt));
                break;
            }

        string ans2;
        vector <int> v2;
        for (int j = n - 1; j >= 0; j--)
            if ((s[j] - '0') % 3 == 2)
                v2.pb(j);
        if (v2.size() >= 2) {
            ans2 = s;
            ans2.erase(v2[0], 1);
            ans2.erase(v2[1], 1);
            int cnt = 0;
            while (cnt < ans2.size() && ans2[cnt] == '0')
                cnt++;
            ans2.erase(0, min((int)ans2.size() - 1, cnt));
        }
        if (ans1.size() == 0 && ans2.size() == 0)
            cout << "-1";
        else if (ans1.size() > ans2.size())
            cout << ans1;
        else
            cout << ans2;
    }

    if (sum == 2) {
        string ans1;
        for (int j = n - 1; j >= 0; j--)
            if ((s[j] - '0') % 3 == 2) {
                ans1 = s;
                ans1.erase(j, 1);
                int cnt = 0;
                while (cnt < ans1.size() && ans1[cnt] == '0')
                    cnt++;
                ans1.erase(0, min((int)ans1.size() - 1, cnt));
                break;
            }

        string ans2;
        vector <int> v2;
        for (int j = n - 1; j >= 0; j--)
            if ((s[j] - '0') % 3 == 1)
                v2.pb(j);
        if (v2.size() >= 2) {
            ans2 = s;
            ans2.erase(v2[0], 1);
            ans2.erase(v2[1], 1);
            int cnt = 0;
            while (cnt < ans2.size() && ans2[cnt] == '0')
                cnt++;
            ans2.erase(0, min((int)ans2.size() - 1, cnt));
        }
        if (ans1.size() == 0 && ans2.size() == 0)
            cout << "-1";
        else if (ans1.size() > ans2.size())
            cout << ans1;
        else
            cout << ans2;
    }
}