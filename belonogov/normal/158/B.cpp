#include <iostream>
#include <cstdio>

using namespace std;
int a[100];

int main(){
     int n, i, x, cnt = 0, k;
    cin >> n;
    for (i = 0; i < n; i++){
        cin >> x;
        a[x]++;
    }
    k = min(a[3], a[1]);
    cnt += k;
    a[3] -= k;
    a[1] -= k;
    cnt += a[3];
    a[3] = 0;

    k = a[2] / 2;
    cnt += k;
    a[2] -= k * 2;

    cnt += a[4];
    a[4] = 0;
    
    cnt += (a[1] + a[2]*2 + 3) / 4;
    cout << cnt;
    return 0;
}