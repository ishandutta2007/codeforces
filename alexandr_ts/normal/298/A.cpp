#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e5 + 10;
const int INF = 2e9 + 1;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-8;
const int MAX = 5e6 + 1;
const int MAX2 = 1e4;

int a[N];

int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    string s1, s;
    cin >> s;

    int l = 0, r = 0;
    fr(i, s.size())
        if (s[i] == 'L')
            l++;
        else if (s[i] == 'R')
            r++;

    int l1, r1;
    fr(i, s.size())
        if (s[i] != '.') {
            l1 = i + 1;
            break;
        }
    for (int i = (int)s.size() - 1; i >= 0; i--)
        if (s[i] != '.') {
            r1 = i + 1;
            break;
        }

    if (!r) {
        cout << r1 << " " << l1 - 1;
        return 0;
    }
    if (!l) {
        cout << l1 << " " << r1 + 1;
        return 0;
    }
    fr(i, n - 1) {
        if (s[i] == 'R' && s[i + 1] == 'L') {
            cout << i + 1 << " " << i + 1;
            return 0;
        }
    }




}