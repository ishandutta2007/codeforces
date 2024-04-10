#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin >> n;
    int maxi=0;
    while (n--){
        int x, y;
        cin >> x >> y;
        maxi=max(maxi, x+y);
    }
    cout << maxi;
}