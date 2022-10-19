#include <bits/stdc++.h>
using namespace std;
long long n,a[10000+5];
int main(){
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    cout << n+1 << endl;
    long long tong=0;
    for (int i=1;i<=n;i++){
        a[n+1-i]=a[n+1-i]+tong;
        long long x=((1000000-i-a[n+1-i]%1000000)+1000000)%1000000;
        tong+=x;
        cout << 1 << " " << n+1-i << " " << x << endl;
    }
    cout << 2 << " " << n << " " << 1000000 << endl;
}