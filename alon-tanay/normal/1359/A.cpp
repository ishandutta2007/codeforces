#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t,n,m,k,ws,ls;
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t;
    for(int i = 0; i < t; i ++) {
        cin >> n >> m >> k;
        ws = min(n/k,m);
        ls = (m-ws)/(k-1);
        if(ls*(k-1) != m-ws) {ls++;}
        cout << ws-ls << endl;
    }
    return 0;
}