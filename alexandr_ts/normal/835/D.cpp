#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ld EPS = 1e-6;
const ll INF = 1e9 + 10;
const int M = 103;
const int N = 5010;

string s;
int od[N], ev[N];

void prec(int n) {
    fr(i, n) {
        int l = i, r = i;
        while (l - 1 >= 0 && r + 1 < n && s[l - 1] == s[r + 1])
            l--, r++;
        od[i] = r - i;
    }
    fr(i, n - 1) {
        if (s[i] == s[i + 1]) {
            int l = i, r = i + 1;
            while (l - 1 >= 0 && r + 1 < n && s[l - 1] == s[r + 1])
                l--, r++;
            ev[i] = i - l + 1;
        }
    }
}

int d[N][N];
int ans[N];

int main() {
    //srand(time(NULL));
    //ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    cin >> s;
    int n = s.size();
    prec(n);
    //fr(i, n) cout << ev[i] << " " << od[i] << endl;
    fr(i, n)
        d[i][i] = 1;
    frab(len, 1, n + 1)
        fr(l, n - len + 1) {
            int r = l + len - 1;
            if ((r - l + 1) % 2) {
                int m = (l + r) / 2;
                int len = (r - l) / 2;
                if (od[m] < len)
                    d[l][r] = 0;
                else
                    d[l][r] = d[l][m - 1] + 1;
            }
            else {
                int m = (l + r) / 2;
                int len = (r - l + 1) / 2;
                if (ev[m] < len)
                    d[l][r] = 0;
                else
                    d[l][r] = d[l][m] + 1;
            }
        }
//    fr(i, n) {
//        fr(j, n)
//            cout << d[i][j] << " ";cout << endl;}
    fr(l, n)
        frab(r, l, n)
            ans[d[l][r]]++;
    for (int i = n; i >= 0; i--)
        ans[i] += ans[i + 1];
    frab(i, 1, n + 1)
        cout << ans[i] << " ";
}