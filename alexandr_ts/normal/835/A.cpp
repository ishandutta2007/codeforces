#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ld EPS = 1e-6;
const ll INF = 1e9 + 10;
const int M = 1e3 + 10;
const int N = 1e6 + 10;



int main() {
    //srand(time(NULL));
    //ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    int s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    int c1 = 2 * t1 + s * v1;
    int c2 = 2 * t2 + s * v2;
    if (c1 < c2)
        cout << "First";
    else if (c1 > c2)
        cout << "Second";
    else
        cout << "Friendship";
}