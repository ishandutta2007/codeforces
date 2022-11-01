#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
const int M = 301;
const int INF = 2e9 + 10;
const int MOD = 1e9 + 7;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '_' + s + '_';
    int cnt = 0, maxlen = 0, curlen = 0;
    bool br = false;
    fr(i, n + 2) {
        if (s[i] == '(')
            br = true;
        if (s[i] == ')')
            br = false;
        if (isalpha(s[i]))
            curlen++;
        if (isalpha(s[i]) && !isalpha(s[i + 1])) {
            if (br)
                cnt++;
            if (!br)
                maxlen = max(maxlen, curlen);
            curlen = 0;
        }
    }
    cout << maxlen << " " << cnt;
}