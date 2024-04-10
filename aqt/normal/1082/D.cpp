#include <bits/stdc++.h>

using namespace std;

int N;
int arr[505];
int L, S;
bool part[505];

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        if(arr[i] == 1){
            L++;
        }
        S += arr[i];
    }
    if(S < 2*N-2){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << " " << min((N-1), N-1-(L-2)) << endl;
    cout << N-1 << endl;
    int s = 1;
    for(int i =1; i<=N; i++){
        if(arr[i] == 1){
            s = i;
        }
    }
    part[s] = 1;
    for(int i = 1; i<=N; i++){
        if(arr[i] >= 2 && !part[i]){
            cout << i << " " << s << endl;
            arr[s]--, arr[i]--;
            s = i;
            part[s] = 1;
        }
    }
    for(int i =1 ; i<=N; i++){
        if(!part[i]){
            for(int j = N; j>=1; j--){
                if(arr[j] && part[j]){
                    cout << i << " " << j << endl;
                    arr[i]--, arr[j]--;
                    break;
                }
            }
        }
    }
}