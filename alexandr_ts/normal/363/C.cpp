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

int a[N], b[N];

int main() {
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    string s1;
    fr(i, s.size())
        if (i >= 2 && s[i] == s[i - 1] && s[i] == s[i - 2])
            continue;
        else
            s1 += s[i];
    fr(i, s1.size())
        if (i >= 3 && s1[i] == s1[i - 1] && s1[i - 2] == s1[i - 3])
            s1[i] = '%';
    fr(i, s1.size())
        if (s1[i] != '%')
            cout << s1[i];

}