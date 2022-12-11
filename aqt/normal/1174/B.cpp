#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    bool k = 1;
    for(int i= 1; i<=N; i++){
        cin >> arr[i];
        if(i != 1 && arr[i]%2 != arr[i-1]%2){
            k = 0;
        }
    }
    if(!k){
        sort(arr+1, arr+1+N);
    }
    for(int i =1 ; i<=N; i++){
        cout << arr[i] << " ";
    }
}