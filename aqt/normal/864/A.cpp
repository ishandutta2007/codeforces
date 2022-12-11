#include <bits/stdc++.h>

using namespace std;

int N;
int arr[101];

int main(){
    cin >> N;
    for(int i =1 ;i<=N; i++){
        int n;
        cin >> n;
        arr[n]++;
    }
    for(int i= 1; i<=100; i++){
        for(int j = 1; j<=100; j++){
            if(arr[i] + arr[j] != 0 && i!= j && arr[i] == arr[j] && arr[i] + arr[j] == N){
                cout << "YES" << endl;
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}