#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
#ifdef GORILLA
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    int n, k;
    cin >> n >> k;
    if (2 * k > n - 1){
        cout << "-1\n";
        return 0;
    }

    cout << n*k << "\n";

    for (int i = 1; i <= n; ++i)
    for (int j = 0; j < k; ++j)
        cout << i <<" "<< (i + j) % n + 1 << "\n";

    return 0;
}