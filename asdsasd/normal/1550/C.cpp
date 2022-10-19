#include <bits/stdc++.h>
using namespace std;

bool ok(int a1, int a2, int a3, int a4){
    if(a1 <= a2 && a2 <= a4) return false;
    if(a1 >= a2 && a2 >= a4) return false;
    if(a1 <= a3 && a3 <= a4) return false;
    if(a1 >= a3 && a3 >= a4) return false;
    if(a2 <= a3 && a3 <= a4) return false;
    if(a2 >= a3 && a3 >= a4) return false;
    return true;
}

void solve(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    int ans = 2 * n - 1;
    int a1, a2, a3, a4;
    for(int i = 0; i < n - 2; i++){
        a1 = A[i];
        a2 = A[i + 1];
        a3 = A[i + 2];
        if(a1 <= a2 && a2 <= a3) continue;
        if(a1 >= a2 && a2 >= a3) continue;
        ans++;
        if(i != n - 3){
            int a4 = A[i + 3];
            if(ok(a1, a2, a3, a4)) ans++;
        }
    }
    cout << ans << "\n";
}

int main(void){
    int t;
    cin >> t;
    while(t--) solve();
}