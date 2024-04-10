#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef unsigned long long ll;

const int N = 1e2 + 10;
const int INF = 2e9;
const int ALPH = 300;

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int fr = INF, ls = -INF;
    fr(i, n)
        if (a[i])
            fr = min(fr, i), ls = max(ls, i);
    if (fr == INF)
    {
        cout << 0;
        return 0;
    }
    int qua = 0;
    frab(i, fr, ls)
        if (!a[i] && !a[i + 1] || i && !a[i] && !a[i - 1])
            qua++;
    cout << ls - fr + 1 - qua;
}