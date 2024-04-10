#include <bits/stdc++.h>

using namespace std;

int n, m;
double res=0;

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m - 1; i++){
        res+=pow((double) i / m, n);
    }
    res = (double) m - res;
    cout << setprecision(15) << fixed << res;
    return 0;
}