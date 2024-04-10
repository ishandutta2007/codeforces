#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define M 123

long double p[M];
int n;

int main(){
#ifdef GORILLA
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> p[i];

    sort(p, p + n);

    long double ans = 0.0, temp = 0.0;
    long double prod = 1.0, sum = 0.0;

    for (int i = n - 1; i >= 0; --i){
        temp = (1 - p[i]) * temp + prod * p[i];
        prod *= (1 - p[i]);
        ans = max(ans, temp);
    }

    cout.precision(13);
    cout << fixed;

    cout << ans;

    return 0;
}