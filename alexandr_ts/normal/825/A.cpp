#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ld PI = acos(-1);
const ll MAX = 2e7 + 10;
const ll INF = 1e9;
const ld EPS = 1e-9;
const int M = 1e2 + 12;
const int N = 1e6 + 10;



int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cur = 0;
    fr(i, n)
        if (s[i] == '0') {
            cout << cur;
            cur = 0;
        }
        else
            cur++;
    cout << cur;


}