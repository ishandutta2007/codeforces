/// Alexandr Tsaplin 18.08.16

#include "bits/stdc++.h"
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define TASK_NAME "salesman"

using namespace std;

typedef long long ll;

const ll N = 1e5;
const ll INF = 2e9 + 1;
const ll MOD = 1e9 + 7;

int a[N];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    int n;
    cin >> n;
    int m = 0, c = 0;
    fr(i, n) {
        int a, b;
        cin >> a >> b;
        if (a > b)
            m++;
        else if (a < b)
            c++;
    }
    if (m > c)
        cout << "Mishka";
    else if (c > m)
        cout << "Chris";
    else
        cout << "Friendship is magic!^^";
}