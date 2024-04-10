#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
const int M = 1e3 + 10;
const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    string s;
    cin >> s;
    fr(i, s.size())
        a[s[i]]++;
    cout << min(a['B'], min(a['u'] / 2, min(a['l'], min(a['b'], min(a['a'] / 2, min(a['r'], a['s']))))));

}