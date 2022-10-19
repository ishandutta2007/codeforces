#include<bits/stdc++.h>
// #include<atcoder/modint>
using namespace std;
// using namespace atcoder;

void solve(){
	int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    int ma = -1 << 30;
    int ii, jj;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        cin >> A[i][j];
        if(A[i][j] > ma){
            ma = A[i][j];
            ii = i;
            jj = j;
        }
    }
    cout << max(ii + 1, n - ii) * max(jj + 1, m - jj) << "\n";
}

int main(){	
	cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) solve();
}