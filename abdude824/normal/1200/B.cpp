#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int T; cin >> T;
    while (T--) {
        int N, M, K; cin >> N >> M >> K;
 
        vector<int> blocks(N);
        for (auto& x : blocks) cin >> x;
    
        int loc = 0;
        for (; loc < N - 1; loc++) {
            int h1 = blocks[loc];
            int h2 = blocks[loc+1];  
 
            if (h1 > h2) {
                M += (h1 - h2);
                h1 = h2;
            }
 
            if (h2 - h1 <= K) {
                int nh1 = max(0, h2 - K);
                M += (h1 - nh1);
                h1 = nh1;
            }
 
            if ((h2 - h1) > K && M >= (h2 - K - h1)) {
                M -= (h2 - K - h1);
                h1 = (h2 - K);
            }
 
            if (h2 - h1 > K) break;
        }
 
        cout << (loc == N - 1 ? "YES" : "NO") << "\n";
    }
}