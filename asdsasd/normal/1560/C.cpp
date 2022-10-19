#include<bits/stdc++.h>
using namespace std;

void solve(){
    int k;
    cin >> k;
    int z = sqrt(k);
    z = max(z - 2, 0);
    while(z * z < k) z++;
    int x = k - (z - 1) * (z - 1);
    if(x <= z){
        cout << x << " " << z << "\n";
    }
    else{
        cout << z << " " << z * 2 - x << "\n";
    }
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    
}