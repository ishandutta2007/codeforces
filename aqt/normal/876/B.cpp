#include <bits/stdc++.h>

using namespace std;

int fre[100005];
int N, K, M;
int arr[100005];

int main(){
    cin >> N >> K >> M;
    for(int i =1 ; i<=N; i++){
        cin >> arr[i];
        fre[arr[i]%M]++;
    }
    for(int i = 0; i<M; i++){
        if(fre[i] >= K){
            cout << "Yes" << endl;
            for(int j = 1; j<=N && K; j++){
                if(arr[j]%M == i){
                    cout << arr[j] << " ";
                    K--;
                }
            }
            return 0;
        }
    }
    cout << "No" << endl;
}