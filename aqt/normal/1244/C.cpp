#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long N, P, W, D;
    cin >> N >> P >> W >> D;
    /*
    long long L = W*D/__gcd(W, D);
    long long k = P/L*L/W;
    N -= k;
    P %= L;
    */
    long long k = 0;
    for(long long i = 0; i<=min(2000000LL, N); i++){
        if((P-W*i)%D == 0 && (P-W*i)/D+i <= N && P-W*i >= 0){
            cout << (k+i) << " " << (P-W*i)/D << " " << N-i-(P-W*i)/D << "\n";
            return 0;
        }
        if((P-D*i)%W == 0 && (P-D*i)/W+i <= N && P-D*i >= 0){
            cout << k+(P-D*i)/W << " " << i << " " << N-i-(P-D*i)/W << "\n";
            return 0;
        }
    }
    cout << -1 << endl;
}