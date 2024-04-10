#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int temp = n/k;
        if(n%k > k/2){
            cout << temp*k+k/2 << "\n";
        }
        else{
            cout << n << "\n";
        }
    }
}