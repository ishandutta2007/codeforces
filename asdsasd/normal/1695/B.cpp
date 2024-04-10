#include<bits/stdc++.h>
// #include<atcoder/modint>
using namespace std;
// using namespace atcoder;

void solve(){
	int n;
    cin >> n;
    vector<long long> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    if(n & 1){
        cout << "Mike" << "\n";
        return;
    }
    int mi = 1 << 30;
    int ind = -1;
    for(int i = 0; i < n; i++){
        if(A[i] < mi){
            mi = A[i];
            ind = i;
        }
    }
    cout << ((ind&1)? "Mike":"Joe") << "\n";

}

int main(){	
	cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) solve();
}