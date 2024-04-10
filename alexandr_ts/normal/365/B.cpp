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
const int MOD = 1e9 + 7;

int a[N];
int fib[N];

int main() {
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    fib[0] = 1;
    fib[1] = 2;
    frab(i, 2, n)
        if (a[i] == a[i - 1] + a[i - 2])
            fib[i] = fib[i - 1] + 1;
        else
            fib[i] = 2;
    cout << *max_element(fib, fib + n);
}