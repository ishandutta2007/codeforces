#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

const int maxn = 1e5 + 100000;
long long a[maxn];

int main (){
    ios_base::sync_with_stdio(false);
    long long n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (k == 1){
        sort (a, a + n);
        cout << a[0] << endl;
    }
    else if (k >= 3){
        sort (a, a + n);
        cout << a[n - 1] << endl;
    }
    else if (k == 2){
        cout << 1ll * max(a[n - 1], a[0]);
    }
    return 0;
}