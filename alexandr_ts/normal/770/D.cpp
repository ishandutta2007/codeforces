#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e3 + 3;
const ll MOD = 10000*100000 + 7;
const ll INF = 2e15 + 10;
const ll MAX = 10000000;

int lvl[N];

char ans[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    string s;
    int n;
    cin >> n;
    cin >> s;

    int bal = 0;
    fr(i, n) {
        if (s[i] == '[') {
            lvl[i] = bal;
            bal++;
        }
        else {
            bal--;
            lvl[i] = bal;
        }
    }
    
    fr(i, N)
        fr(j, N)
            ans[i][j] = ' ';
    
    int mx = *max_element(lvl, lvl + n);
    fr(i, n)
        lvl[i] = mx - lvl[i];
    int h = 3 + 2 * mx;
    int cur = 0;
    fr(i, n) {
        ans[(h - 3) / 2 - lvl[i]][cur] = '+';
        ans[h - 1 - ((h - 3) / 2 - lvl[i])][cur] = '+';
        if (s[i] == '[' && s[i + 1] == ']')
            cur += 3;
        cur++;
    }
    fr(i, cur) {
        int cnt = 0;
        fr(j, h) {
            if (ans[j][i] == '+')
                cnt++;
            if (ans[j][i] != '+' && cnt == 1)
                ans[j][i] = '|';
        }
    }
    fr(j, h) {
        int bal = 0;
        fr(i, cur) {
            if (ans[j][i] == '+') {
                if (!bal)
                    ans[j][i + 1] = '-';
                else
                    ans[j][i - 1] = '-';
                bal ^= 1;
            }
        }
    }

    fr(i, h) {
        fr(j, cur)
            cout << ans[i][j];
        if (i + 1 < h)
            cout << endl;
    }
}