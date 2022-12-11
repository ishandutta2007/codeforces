#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << "? ";
    for(int i = 0; i<100; i++){
        cout << i << " ";
    }
    cout << endl;
    cout.flush();
    int ans = 0;
    cin >> ans;
    ans /=128;
    ans *= 128;
    cout << "? ";
    for(int i = 128; i<=12800; i+=128){
        cout << i << " ";
    }
    cout << endl;
    cout.flush();
    int n;
    cin >> n;
    n %= 128;
    ans += n;
    cout << "! " << ans << endl;
    cout.flush();
}