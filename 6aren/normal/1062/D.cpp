#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long res=0;
    for (int i=2;i<=n/2;i++){
        int t=n/i;
        res+=(long long) 1 * t*(t+1)/2-1;
    }
    cout << res*4;
}