#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int idxl = 1, idxr = N*N;
    for(int j = 1; j<=N; j++){
        for(int i = 2; i<=N; i+=2){
            cout << idxl << " " << idxr << " ";
            idxl++, idxr--;
        }
        cout << "\n";
    }
}