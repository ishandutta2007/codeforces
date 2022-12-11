#include <bits/stdc++.h>

using namespace std;

int Q;
long long shift[70];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> Q;
    while(Q--){
        int c;
        cin >> c;
        if(c == 1){
            long long L, K;
            cin >> L >> K;
            L = 63 - __builtin_clzll(L);
            shift[L] += K;
            shift[L] %= (1LL<<L);
            if(shift[L] < 0){
                shift[L] += (1LL<<L);
            }
        }
        else if(c == 2){
            long long L, K;
            cin >> L >> K;
            L = 63 - __builtin_clzll(L);
            K %= (1LL<<L);
            if(K < 0){
                K += (1LL<<L);
            }
            for(long long i = L; i<60; i++){
                shift[i] += K;
                shift[i] %= (1LL<<i);
                if(shift[i] < 0){
                    shift[i] += (1LL<<i);
                }
                K *= 2;
            }
        }
        else{
            long long X;
            cin >> X;
            long long L = 63 - __builtin_clzll(X);
            long long N = X - (1LL<<L);
            N += shift[L];
            N %= (1LL<<L);
            if(N < 0){
                N += (1LL<<L);
            }
            N += (1LL<<L);
            for(; L >=0; L--){
                long long T = N - (1LL<<L);
                T -= shift[L];
                T %= (1LL<<L);
                if(T < 0){
                    T += (1LL<<L);
                }
                cout << T + (1LL<<L) << " ";
                N >>= 1LL;
            }
            cout << "\n";
        }
    }
}