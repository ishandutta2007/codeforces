#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const int N = 1e3;

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    frab(i, 1, N)
        if (i * (i + 1) <= 2 * n && (i + 2) * (i + 1) > 2 * n) {
            cout << i << endl;
            frab(j, 1, i)
                cout << j << " ";
            cout << n - (i - 1) * i / 2;
            return 0;
        }
}