#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
const int M = 301;
const int INF = 2e9 + 10;
const int MOD = 1e9 + 7;

int a[N];
int b[N];

int dist(char a, char b) {
    return min(abs(a - b), min(abs(a + 26 - b), abs(b + 26 - a)));
}

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    vector <int> ans;
    while (n)
        if (n == 3) {
            ans.pb(3);
            break;
        }
        else if (n >= 2) {
            ans.pb(2);
            n -= 2;
        }
    cout << ans.size() << endl;
    fr(i, ans.size())
        cout << ans[i] << " ";
}