#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 3;

unordered_map <int, int> m;

pair <int, int> a[N];

bool cmp(pair <int, int> a, pair <int, int> b) {
    if (m[a.first] != m[b.first])
        return m[a.first] < m[b.first];
    else
        return m[a.second] < m[b.second];
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    string s, t;
    char c;
    int pw = 0;
    int i = 0, dt = -1;
    while (cin >> c) {
        if (c == '.')
            dt = i;
        else if (c == 'e')
            break;
        else if (dt == -1)
            s += c;
        else
            t += c;
        i++;
    }
    cin >> pw;

    //cout << s << " " << t << " " << pw << endl;

    fr(i, pw) {
        if (t.size()) {
            s += t[0];
            t.erase(0, 1);
        }
        else
            s += '0';
    }
    if (t.size())
        s = s + "." + t;//cout << s << "." << t;
    //else
       // cout << s;
    while (s[0] == '0' && s.size() > 1 && s[1] != '.')
        s.erase(0, 1);
    bool dotu = false;
    fr(i, s.size())
        if (s[i] == '.') dotu = true;
    if (dotu) {
        while (s[(int)s.size() - 1] == '0')
            s.erase((int)s.size() - 1, 1);
    }
    if (s[(int)s.size() - 1] == '.')
        s.erase((int)s.size() - 1, 1);
    cout << s;
}