#include <bits/stdc++.h>

using namespace std;

int N, K;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    if(1LL*K*(K-1) < N){
        cout << "no" << endl;
        return 0;
    }
    cout <<"yes" << endl;
    for(int i = 1; N; i++){
        for(int j = 0; j<K && N; j++){
            cout << j+1 << " " << (j+i)%K+1 << endl;
            N--;
        }
    }
}