#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e5 + 3;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    sort(a, a + n);
    cout << a[n / 2];
}