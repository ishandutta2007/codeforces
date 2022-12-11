#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int h, m;
        cin >> h >> m;
        cout << (24-h-1)*60 + 60-m << endl;
    }
}