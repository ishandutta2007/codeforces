#include <bits/stdc++.h>

using namespace std;

int N;
int arr[200005];
int pre0[200005], pre1[200005];

int main(){
    cin>> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        pre0[i] = pre0[i-1];
        pre1[i] = pre1[i-1];
        if(i%2){
            pre1[i] += arr[i];
        }
        else{
            pre0[i] += arr[i];
        }
    }
    int cnt = 0;
    for(int i = 1; i<=N; i++){
        if(i%2){
            if(pre1[i]-arr[i]+pre0[N]-pre0[i] == pre0[i]+pre1[N]-pre1[i]){
                cnt++;
            }
        }
        else{
            if(pre0[i]-arr[i]+pre1[N]-pre1[i] == pre1[i]+pre0[N]-pre0[i]){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}