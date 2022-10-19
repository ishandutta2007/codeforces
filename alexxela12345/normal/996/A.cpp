#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n;
    cin >> n;
    int cnt = 0;
    while (n >= 100) {
        cnt++;
        n-=100;
    }
    while (n >= 20) {
        cnt++;
        n -= 20;
    }
    while (n >= 10) {
        cnt++;
        n -= 10;
    }
    while (n >= 5) {
        cnt ++ ;
        n -= 5;
    }
    cnt += n;
    cout << cnt;
    return 0;    
}