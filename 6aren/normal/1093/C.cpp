#include <bits/stdc++.h>
using namespace std;

const int N=200000+5;

long long n, b[N], a[N];

int main(){
    cin >> n;
    for (int i=1; i<=n/2; i++){
        cin >> b[i];
    }
    a[1]=0;
    a[n]=b[1];
    for (int i=2; i<=n/2; i++){
        a[i]=max(a[i-1], b[i]-a[n+2-i]);
        a[n+1-i]=b[i]-a[i];
    }
    for (int i=1; i<=n; i++){
        cout << a[i] << " ";
    }
}