#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 1;
const int INF = 2e9 + 1;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-8;
const int MAX = 1e6 + 1;

int main() {
    //freopen("input.txt", "r", stdin);
    int x;
    string s;
    cin >> x;
    cin >> s;
    cin >> s;
    if (s == "week") {
        if (x == 5 || x == 6)
            cout << 53;
        else
            cout << 52;
    }
    if (s == "month") {
        if (x <= 29)
            cout << 12;
        else if (x <= 30)
            cout << 11;
        else if (x <= 31)
            cout << 7;
    }
}