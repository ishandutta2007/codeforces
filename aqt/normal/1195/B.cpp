#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long N, K;
    cin >> N >> K;
    for(long long x = 0; x<=N; x++){
        if(x*(x+1)/2 - (N-x) == K && x*(x+1)/2 >= N-x){
            cout << N-x << endl;
            return 0;
        }
    }
}