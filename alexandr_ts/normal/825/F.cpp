#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1000000007;
const ll P1 = 17;
const ll P2 = 19;
const ld PI = acos(-1);
const ll MAX = 63211236 + 10;
const ll INF = 1e9 + 10;
const ld EPS = 1e-9;
const int M = 5e3 + 2;
const int N = 8005;

int pref[N][N];

void p(string &s, int i1) {
    string t = s.substr(i1, (int)s.size() - i1);
    int n = t.size();
    frab(i, 1, n) {
        int j = pref[i1][i - 1];
        while (j >= 1 && t[j] != t[i]) {
            j = pref[i1][j - 1];
        }
        if (j == 0 && t[0] == t[i])
            pref[i1][i] = 1;
        else if (j == 0)
            pref[i1][i] = 0;
        else
            pref[i1][i] = j + 1;
    }
}

int numLen(int n) {
    int ans = 0;
    while (n) {
        ans++;
        n /= 10;
    }
    return ans;
}

int len(int l, int r) {
    int h = (r - l + 1);
    if (pref[l][h - 1] * 2 < h)
        return 1 + h;
    int prefLen = h - pref[l][h - 1];
    assert(prefLen != 0);
    if (h % prefLen == 0) {
        return prefLen + numLen(h / prefLen);
    }
    else
        return 1 + h;
}

int d[N];

int main() {
    //freopen("a.in", "r", stdin);
    string s;
    cin >> s;
    int n = s.size();
    fr(i, n)
        p(s, i);

//    fr(i, n) {
//        fr(j, n)
//            cout << pref[i][j] << " ";
//        cout << endl;
//        }
    fill(d, d + n + 1, INF);
    d[0] = 0;
    frab(i, 1, 1 + n) {
        fr(j, i) {
            //cout << i - 1 << " " << j << " " << len(j, i - 1) << endl;
            d[i] = min(d[i], d[j] + len(j, i - 1));
        }
    }

    cout << d[n];


}