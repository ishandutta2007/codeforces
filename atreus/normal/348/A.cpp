#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    long long sum = 0, mx = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        sum += a;
        mx = max(mx, 1ll * a);
    }
    long long r = 1000000000000;
    long long l = 0;
    while (r - l > 1){
        long long y = (r + l) / 2;
        if ((n - 1) * y >= sum)
            r = y;
        else
            l = y;
    }
    cout << max(r, mx) << endl;
}