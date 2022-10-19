#include<bits/stdc++.h>
//#include<atcoder/dsu>
using namespace std;
//using namespace atcoder;

void solve(){
	int n;
    cin >> n;
    vector<long long> A(n), B(n, 0), C(n, 0);
    for(int i = 0; i < n; i++) cin >> A[i];
    C[0] = A[0];
    for(int i = 1; i < n; i++){
        B[i] = B[i - 1];
        C[i] = C[i - 1];
        if(B[i] + C[i] < A[i]) B[i] = A[i] - C[i];
        else C[i] = A[i] - B[i];
    }
    long long ans = B[n - 1] + C[0];
    ans += -2 * min(C[n - 1], 0LL);
    cout << ans << "\n";

}

int main(){	
	cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) solve();
}