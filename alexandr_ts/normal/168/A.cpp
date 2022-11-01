#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define read(a) scanf("%d", &a)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 4e5;
const int INF = 2e9 + 1;

int main() {
    //freopen("input.txt", "r", stdin);
    int n, x, y;
    cin >> n >> x >> y;
    cout << max(0, (n * y - 100 * x + 99) / 100);
}