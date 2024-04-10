#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 1e5;
const int INF = 2e9 + 1;

int main() {
    //freopen("input.txt", "r", stdin);
    int a[10];
    int n;
    cin >> n;
    fr(i, 7)
        cin >> a[i];
    fr(i, INF) {
        n -= a[i % 7];
        if (n <= 0) {
            cout << i % 7 + 1;
            return 0;
        }
    }
}