#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T; while(T--) {
        int N; cin >> N;
        vector<vector<int>> V(2*N, vector<int>(2*N));
        for(auto&x: V) for(int&y: x) cin >> y;
        long long ans = 0;
        for(int i=N; i<2*N; ++i) for(int j=N; j<2*N; ++j) ans += V[i][j];
        ans += min({
            V[0][N], V[N][0],
            V[N-1][N], V[N][N-1],
            V[0][2*N-1], V[2*N-1][0],
            V[N-1][2*N-1], V[2*N-1][N-1]
        });
        cout << ans << endl;
    }
}