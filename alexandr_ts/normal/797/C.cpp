#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const int INF = 1e9 + 10;
const ld EPS = 1e-9;
const int M = 1003;
const int N = 1e6 + 2;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    string t, u;
    frab(ch, 'a', 'z' + 1) {
        while (t.size() && t.back() <= ch) {
            u += t.back();
            t.pop_back();
        }

        int last = -1;
        for (int i = (int)s.size() - 1; i >= 0 && last == -1; i--)
            if (s[i] == ch)
                last = i;

        if (last != -1)
            fr(j, last + 1)
                if (s[j] == ch) {
                    u += ch;
                }
                else
                    t += s[j];
        if (last != -1)
            s = s.substr(last + 1, (int)s.size() - last - 1);
        //cout << s << " " << t << " " << u << endl;
    }

    while (t.size()) {
        u += t.back();
        t.pop_back();
    }

    cout << u;
}