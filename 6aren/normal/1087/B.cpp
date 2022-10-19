#include <bits/stdc++.h>
using namespace std;

int n, k;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    int mini=2e9;
    for (int i=1; i*i<=n; i++){
        if (n%i) continue;
        int j=n/i;
        if (i<k) mini=min(mini, j*k+i);
        if (j<k) mini=min(mini, i*k+j);
    }
    cout << mini;
}