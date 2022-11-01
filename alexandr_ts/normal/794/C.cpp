#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 7;
const ll MOD = 1e9 + 7;
const ll P = 29;
const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e6 + 10;
const int M = 1e3 + 10;

char ans[N];

int cnt1[N], cnt2[N];

bool ok(int *a, int *b) {
    int al = INF, br = -INF;
    fr(i, 26)
        if (a[i])
            al = min(al, i);
    fr(i, 26)
        if (b[i])
            br = i;
    return al >= br;
}

int lft(int *a) {
    fr(i, 26)
        if (a[i])
            return i;
}

int rgt(int *a) {
    for (int i = 25; i >= 0; i--)
        if (a[i])
            return i;
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    string s1, s2;
    cin >> s1 >> s2;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    reverse(s2.begin(), s2.end());
    int n = s1.size();
    s1.resize((n + 1) / 2);
    s2.resize(n / 2);
    fr(i, s1.size())
        cnt1[s1[i] - 'a']++;
    fr(i, s2.size())
        cnt2[s2[i] - 'a']++;

    int curl = 0, curr = n - 1;

    int step = 0;

    while (curl <= curr) {
        if (!step) {
            if (ok(cnt1, cnt2)) {
                int t = rgt(cnt1);
                ans[curr] = (char)(t + 'a');
                curr--;
                cnt1[t]--;
            }
            else {
                int t = lft(cnt1);
                ans[curl] = (char)(t + 'a');
                curl++;
                cnt1[t]--;
            }
        }
        else {
            if (ok(cnt1, cnt2)) {
                int t = lft(cnt2);
                ans[curr] = (char)(t + 'a');
                curr--;
                cnt2[t]--;
            }
            else {
                int t = rgt(cnt2);
                ans[curl] = (char)(t + 'a');
                curl++;
                cnt2[t]--;
            }
        }
        step = !step;
    }

    fr(i, n)
        cout << ans[i];
}