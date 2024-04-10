#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e5 + 1;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const ld PI = acos(-1);
const int MOD = 1e9 + 7;
map <string, int> m;

int main() {
    string s;
    cin >> s;
    fr(i, 10) {
        string tmp;
        cin >> tmp;
        m[tmp] = i;
    }
    fr(i, 8) {
        string tmp;
        for (int j = 10 * i; j < 10 * i + 10; j++)
            tmp += s[j];
        cout << m[tmp];
    }



}