#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long A, B, C;
    cin >> A >> B >> C;
    long long ans = 2*min(A, B) + 2*C;
    if(A != B){
        ans = 2*min(A, B)+1+2*C;
    }
    cout << ans;
}