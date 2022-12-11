#include <bits/stdc++.h>

using namespace std;

int N;
int arr[1005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int S = 0;
    for(int i = 1; i<=N; i++){
        cin>> arr[i];
        S += arr[i];
    }
    if(S){
        cout << "YES" << endl;
        cout << 1 << "\n" << 1 << " " << N << endl;
        return 0;
    }
    else{
        for(int i = 1; i<N; i++){
            if(arr[i] != 0){
                cout << "YES" << endl;
                cout << 2 << endl;
                cout << 1 << " " << i << endl;
                cout << (i+1) << " " << N << endl;
                return 0;
            }
        }
        cout << "NO" << endl;
    }
}