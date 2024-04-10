#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 5;
const int M = 500 * 1000 * 1000;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-7;

int a[N];

int f(string s) {
    if (s == "monday") return 1;
    if (s == "tuesday") return 2;
    if (s == "wednesday") return 3;
    if (s == "thursday") return 4;
    if (s == "friday") return 5;
    if (s == "saturday") return 6;
    if (s == "sunday") return 0;
}

int main() {
    //freopen("a.in", "r", stdin);
    string s, t;
    cin >> s >> t;
    int a1 = f(s), a2 = f(t);
    if ((a1 + 31) % 7 == a2 || (a1 + 30) % 7 == a2 || (a1 + 28) % 7 == a2)
        cout << "YES";
    else
        cout << "NO";
}