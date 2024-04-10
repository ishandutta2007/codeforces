#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef unsigned long long ll;

const int N = 1e6 + 10;
const int INF = 2e9;
const int ALPH = 300;

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    //freopen("a.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    if (k > n || k == 1 && n > 1) {
        cout << -1;
        return 0;
    }
    if (k == 1 && n == 1) {
        cout << "a";
        return 0;
    }
    for (int i = n - 1; i > n - 1 - k + 2; i--)
        a[i] = k - ((n - 1) - i) - 1;
    fr(i, n - k + 2)
        if (i % 2)
            a[i] = 1;
        else
            a[i] = 0;
    fr(i, n)
        cout << (char)(a[i] + 'a');

}