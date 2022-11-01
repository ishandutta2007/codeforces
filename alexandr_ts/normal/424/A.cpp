#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e3 + 1;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const int MOD = 1e9 + 7;

int main() {
    string s;
    int n;
    cin >> n;
    cin >> s;
    int cx = 0, cX = 0;
    fr(i, n)
        if (s[i] == 'x') cx++;
        else cX++;
    int ans = abs(cx - cX) / 2;
    cout << ans << endl;
    fr(i, n)
        if (cx < cX && s[i] == 'X' && ans)
            s[i] = 'x', ans--;
        else if (cx > cX && s[i] == 'x' && ans)
            s[i] = 'X', ans--;
    cout << s;
}