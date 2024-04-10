#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int u = 0; u < n; u++){
        cin >> a[u];
    }
    sort(a, a+n);

    if(k > n || (k < n-1 && a[n-k] == a[n - k - 1])){
        cout << -1;
    }
    else{
        cout << 0 << " " << a[n-k];
    }
    return 0;
}