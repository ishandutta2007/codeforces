#include<bits/stdc++.h>
using namespace std;
#define int long long
main(){
    int n, k;
    cin >> n >> k;
    for(int i=k-1;i>=1;i--){
        if(n%i) continue;
        int fs = n/i;
        cout << fs*k+i;
        exit(0);
    }
}