#include <bits/stdc++.h>

using namespace std;

int main(){
    cout.tie(0);
    int N, K;
    cin >> N >> K;
    int P = (N-K)/2;
    for(int i = 1; i<=N; i++){
        if(i%(P+1) == 0){
            cout << 1;
        }
        else{
            cout << 0;
        }
    }
}