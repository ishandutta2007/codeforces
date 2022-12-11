#include <bits/stdc++.h>

using namespace std;

int N;
int arr1[200005], arr2[200005];

int main(){
    cin >> N;
    for(int i =1; i<=N; i++){
        cin >> arr1[i];
    }
    for(int i = 1; i<=N; i++){
        cin >> arr2[i];
    }
    int idx = 1, cnt = 0;
    for(int i = 1; i<=N; i++){
        while(idx <= N){
            if(arr1[i] != arr2[idx]){
                idx++;
            }
            else{
                cnt++;
                break;
            }
        }
    }
    cout << N-cnt<< endl;
}