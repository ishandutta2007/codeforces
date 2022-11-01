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
    int pos = 0;
    string a, b;
    fr(i, s.size())
        if (s[i] == '.') {
            pos = i;
            break;
        }
        else
            a += s[i];
    frab(i, pos + 1, s.size())
        b += s[i];
    if (a[(int)a.size() - 1] == '9') {
        cout << "GOTO Vasilisa.";
        return 0;
    }
    if (b[0] >= '5')  {
        a[(int)a.size() - 1]++;
    }
    cout << a;

}