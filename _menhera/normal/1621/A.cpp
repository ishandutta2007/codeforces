#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while(T--) {
        int N, K; cin >> N >> K;
        if(N >= 2*K-1)
        {
            vector<string> V(N, string(N, '.'));
            for(int i=0; i<K; ++i) V[2*i][2*i] = 'R';
            for(auto x: V) cout << x << '\n';
        }
        else cout << "-1\n";
    }
}