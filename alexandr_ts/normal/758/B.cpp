#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e4 + 1;
const int M = 1e7 + 1;;
const ll INF = 2e9 + 10;
const ll MOD = 1000*1000*1000 + 7;
const ld EPS = 1e-9;

ll n, m, k, x, y;

int a[4];

int main() {
    //freopen("a.in", "r", stdin);
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    string s2 = "aaaa";
    fr(i, s.size())
        if (s[i] != '!')
            s2[i % 4] = s[i];
    fr(i, s.size())
        if (s[i] == '!')
            a[i % 4]++;

    fr(i, 4)
        if (s2[i] == 'R')
            cout << a[i] << endl;
    fr(i, 4)
        if (s2[i] == 'B')
            cout << a[i] << endl;
    fr(i, 4)
        if (s2[i] == 'Y')
            cout << a[i] << endl;
    fr(i, 4)
        if (s2[i] == 'G')
            cout << a[i] << endl;

}