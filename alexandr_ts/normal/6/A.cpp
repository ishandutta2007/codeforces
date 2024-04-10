#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef unsigned long long ll;

const int N = 1e5;
const int INF = 2e9;
const int ALPH = 300;

int a[N];

int main() {
    srand(time(NULL));
    //freopen("a.in", "r", stdin);
    fr(i, 4)
        cin >> a[i];
    fr(i, 10000) {
        random_shuffle(a, a + 4);
        if (a[0] + a[1] > a[2] && a[0] + a[2] > a[1] && a[2] + a[1] > a[0]) {
            cout << "TRIANGLE";
            return 0;
        }
    }
    fr(i, 10000) {
        random_shuffle(a, a + 4);
        if (a[0] + a[1] == a[2]) {
            cout << "SEGMENT";
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
}