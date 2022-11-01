#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e2 + 1;
const ll INF = 3e18;
const ll MAX = 1e6 + 1;
const ll ALPH = 300;
const ld EPS = 1e-12;
const ll MOD = 1e9 + 7;

string f(string s) {
    if (s.size() % 2) return s;
    int m = s.size() / 2;
    string s1 = f(s.substr(0, m));
    string s2 = f(s.substr(m, s.size()));
    if (s1 > s2) swap(s1, s2);
    return s1 + s2;
}

int main() {
    string s, t;
    cin >> s >> t;
    //cout << f(s) << endl << f(t) << endl;
    (f(s) == f(t)) ? cout << "YES" : cout << "NO";
}