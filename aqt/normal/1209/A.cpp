#include <bits/stdc++.h>

using namespace std;

int N;
int arr[105];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+1+N);
    int cnt = 0;
    for(int i = 1; i<=N; i++){
        bool b = 1;
        for(int j = 1; j<i; j++){
            if(arr[i]%arr[j] == 0){
                b = 0;
            }
        }
        cnt += b;
    }
    cout << cnt << endl;
}