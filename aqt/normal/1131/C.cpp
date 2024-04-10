#include <bits/stdc++.h>

using namespace std;

int arr[105];

int main(){
    int N;
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+N+1);
    for(int i = 1; i<=N; i+=2){
        cout << arr[i] << " ";
    }
    if(N%2){
        for(int i = N-1; i>0; i-=2){
            cout << arr[i] << " ";
        }
    }
    else{
        for(int i = N; i>0; i-=2){
            cout << arr[i] << " ";
        }
    }
}