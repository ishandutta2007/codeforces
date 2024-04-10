#include <bits/stdc++.h>

using namespace std;

int arr[200005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    if(N%2 == 0){
        cout << "NO" << endl;
        return 0;
    }
    for(int i =1 ; i<=N; i++){
        if(i%2 == 1){
            arr[i] = i;
            arr[i+N] = i+1;
        }
        else{
            arr[i] = 2*N-i+2;
            arr[i+N] = 2*N-i+1;
        }
    }
    cout << "YES" << "\n";
    for(int i = 1; i<=2*N; i++){
        cout << arr[i] << " ";
    }
}