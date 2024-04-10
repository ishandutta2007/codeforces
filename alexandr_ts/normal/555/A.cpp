#include <bits/stdc++.h>
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;
const ll INF = 1e12;
const ld EPS = 1e-10;

int main() {
    //freopen("a.in", "r", stdin);
    int n, k, qua, tmp;
    bool st = false;
    int x = 1;
    int last = -INF;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> qua;
        last = -INF;
        st = false;
        for (int j = 0; j < qua; j++) {
            last = tmp;
            cin >> tmp;
            if (tmp == 1)
                st = true;
            else if (st && tmp == last + 1)
                x++;
            else
                st = false;
        }
    }
    cout << 2 * n - 2 * x - k + 1;
}