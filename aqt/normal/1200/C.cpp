#include <bits/stdc++.h>

using namespace std;

long long N, M, Q;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> Q;
    long long G = __gcd(N, M);
    long long ng = N/G, mg = M/G;
    while(Q--){
        long long s1, e1, s2, e2;
        cin >> s1 >> e1 >> s2 >> e2;
        e1--, e2--;
        long long b1 = 0, b2 = 0;
        if(s1 == 1){
            b1 = e1/ng;
        }
        else{
            b1 = e1/mg;
        }
        if(s2 == 1){
            b2 = e2/ng;
        }
        else{
            b2 = e2/mg;
        }
        if(b1 == b2){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
}