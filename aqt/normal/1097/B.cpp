#include <bits/stdc++.h>

using namespace std;

int N;
int arr[15];

int main(){
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> arr[i];
    }
    for(int i = 0; i<1<<N; i++){
        int crnt = 0;
        for(int j = 0; j<N; j++){
            if((1<<j)&i){
                crnt += arr[j];
            }
            else{
                crnt -= arr[j];
            }
        }
        if(!(crnt%360)){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}