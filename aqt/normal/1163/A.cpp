#include <bits/stdc++.h>

using namespace std;

int N, M;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    if(M == 0){
        cout << 1 << endl;
    }
    else if(M <= N/2){
        cout << M << endl;
    }
    else{
        cout << N-M << endl;
    }
}