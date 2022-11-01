#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 6e6 + 10;
const ll INF = 2e9;
const ld EPS = 1e-8;
const int MAX = 6e6 + 1;

string s[N];

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    fr(i, n)
        cin >> s[i];
    int x = 0;
    fr(i, s[0].size()) {
        bool er = false;
        fr(j, n)
            if (s[j][i] != s[0][i])
                er = true;
        if (!er)
            x++;
        else
            break;
    }
    cout << x;
}