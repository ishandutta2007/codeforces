#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int a, b, c, r;
        cin >> a >> b >> c >> r;
        if(a > b){
            swap(a, b);
        }
        int l = max(c-r, a);
        int ll = min(c+r, b);
        cout << (b-a-max(0, ll-l)) << "\n";
    }
}