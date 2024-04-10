#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef unsigned long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int MAX = 1e9 + 1;
const int N = 5e3 + 10;

string s[N];
string t[N];
char ch[N];
int l[N], r[N];

int main() {
    //freopen("a.in", "r", stdin);

    int n;
    scanf("%d", &n);
    fr(i, n) {
        scanf("%s", ch);
        s[i] = ch;
    }
    fr(i, n) {
        scanf("%s", ch);
        t[i] = ch;
    }

    fr(i, n) {
        while (l[i] < s[i].size() && s[i][l[i]] == t[i][l[i]])
            l[i]++;
        r[i] = (int)s[i].size() - 1;
        while (r[i] >= 0 && s[i][r[i]] == t[i][r[i]])
            r[i]--;

    }

    string dif0;
    fr(i, n) {
        if (l[i] <= r[i])
            if (dif0.size() && s[i].substr(l[i], r[i] - l[i] + 1) != dif0) {
                cout << "NO";
                return 0;
            } else if (!dif0.size()) {
                dif0 = s[i].substr(l[i], r[i] - l[i] + 1);
            }
    }

    fr(i1, 3001) {
        bool ok = true;
        char ch = '0';
        char cht = '0';
        fr(i, n) {
            if (l[i] > r[i]) continue;
            if (!l[i]) {
                ok = false;
                break;
            }
            if (ch == '0') {
                ch = s[i][l[i] - 1];
                cht = t[i][l[i] - 1];
            } else if (s[i][l[i] - 1] != ch || t[i][l[i] - 1] != cht) {
                ok = false;
                break;
            }
        }
        if (ok) {
            fr(j, n)
                if (l[j] <= r[j])
                    l[j]--;
        } else {
             break;
        }
    }

    fr(i1, 3001) {
        bool ok = true;
        char ch = '0';
        char cht = '0';
        fr(i, n) {
            if (l[i] > r[i]) continue;
            if (r[i] + 1 == s[i].size()) {
                ok = false;
                break;
            }
            if (ch == '0') {
                ch = s[i][r[i] + 1];
                cht = t[i][r[i] + 1];
            } else if (s[i][r[i] + 1] != ch || t[i][r[i] + 1] != cht) {
                ok = false;
                break;
            }
        }
        if (ok) {
            fr(j, n)
                if (l[j] <= r[j])
                    r[j]++;
        } else {
             break;
        }
    }

    string ch1, ch2;
    fr(i, n) {
        //cout << i << " " << l[i] << " " << r[i] << endl;
        if (l[i] <= r[i]) {
            ch1 = s[i].substr(l[i], r[i] - l[i] + 1);
            ch2 = t[i].substr(l[i], r[i] - l[i] + 1);
            break;
        }
    }

    fr(i, n) {
        int pos = s[i].find(ch1);
        if (pos == -1) continue;
        s[i].replace(pos, ch1.size(), ch2);
    }

    bool ok = true;
    fr(i, n)
        if (s[i] != t[i])
            ok = false;
    if (ok) {
        cout << "YES\n";
        cout << ch1 << endl << ch2 << endl;
    }
    else
        cout << "NO";

}