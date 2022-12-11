#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    for(int i = 1, j = N; i<=N/2; i++, j--){
        for(int a = 1, b = M; a<=M; a++, b--){
            cout << i << " " << a << "\n";
            cout << j << " " << b << "\n";
        }
    }
    if(N%2){
        for(int i = 1; i<=(M+1)/2; i++){
            cout << (N+1)/2 << " " << i << "\n";
            if(i != M-i+1){
                cout << (N+1)/2 << " " << (M-i+1) << "\n";
            }
        }
    }
}