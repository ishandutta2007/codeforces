#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef unsigned long long ll;

const int N = 1e5;
const int ALPH = 300;

int a[ALPH], b[ALPH];
int c[ALPH], d[ALPH];

int main() {
    //freopen("a.in", "r", stdin);
    string s, t;
    cin >> s >> t;
    fr(i, s.size()) {
        a[s[i]]++;
        c[tolower(s[i])]++;
    }
    fr(i, t.size()) {
        b[t[i]]++;
        d[tolower(t[i])]++;
    }
    int ans = 0;
    fr(i, ALPH) {
        int x = min(a[i], b[i]);
        ans += x;
        a[i] -= x, b[i] -= x;
        if (isupper((char)i))
            c[i - 'A' + 'a'] -= x, d[i - 'A' + 'a'] -= x;
        else
            c[i] -= x, d[i] -= x;
    }
    int ans2 = 0;
    fr(i, ALPH)
        ans2 += min(c[i], d[i]);
    cout << ans << " " << ans2;



}