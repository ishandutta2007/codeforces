#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    cout << "YES\n";
    while(N--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        c %= 2, d %= 2;
        if(c < 0){
            c += 2;
        }
        if(d < 0){
            d += 2;
        }
        cout << c*2+d+1 << "\n";
    }
}