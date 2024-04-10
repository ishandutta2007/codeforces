#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;
const int INF = 2e9 + 1;

int a[N];

int main() {
    int n;
    cin >> n;
    if (n % 2) {
        cout << 0;
        return 0;
    }
    n /= 2;
    cout << (n - 1) / 2;
}