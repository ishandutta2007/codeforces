#include<bits/stdc++.h>
// #include<atcoder/modint>
using namespace std;
// using namespace atcoder;

void solve(){
	int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> A[i][j];
    if(((n + m) & 1) == 0){
        cout << "NO\n";
        return;
    }
    vector<vector<int>> L(n, vector<int>(m));
    vector<vector<int>> R(n, vector<int>(m));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        if(i == 0 && j == 0){
            L[i][j] = A[i][j];
            R[i][j] = A[i][j];
        }
        else if(i == 0){
            L[i][j] = L[i][j - 1] + A[i][j];
            R[i][j] = R[i][j - 1] + A[i][j];
        }
        else if(j == 0){
            L[i][j] = L[i - 1][j] + A[i][j];
            R[i][j] = R[i - 1][j] + A[i][j];
        }
        else{
            L[i][j] = min(L[i - 1][j], L[i][j - 1]) + A[i][j];
            R[i][j] = max(R[i - 1][j], R[i][j - 1]) + A[i][j];
        }
    }
    cout << ((L[n - 1][m - 1] <= 0 && 0 <= R[n - 1][m - 1])? "YES":"NO") << "\n";
}

int main(){	
	cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) solve();
}