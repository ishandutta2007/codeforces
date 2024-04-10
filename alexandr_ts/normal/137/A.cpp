#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e3 + 10;
const ll INF = 2e9;
const ll ALPH = 300;
const int MOD = 1e9 + 7;
int st[N];

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    string s;
    cin >> s;
    char cur = s[0];
    int cnt = 0, ans = 0;
    fr(i, s.size()) {
        if (s[i] == cur && cnt < 5)
            cnt++;
        else if (s[i] == cur) {
            ans++, cnt = 1;
        }
        else {
            if (cnt) ans++;
            cnt = 1;
            cur = s[i];
        }
    }
    if (cnt) ans++;
    cout << ans;
}