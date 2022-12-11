#include <bits/stdc++.h>

using namespace std;

int arr[3];

int main(){
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr+3);
    for(int i = 1; i<=2; i++){
        if(arr[i-1] == i){
            cout << "YES" << endl;
            return 0;
        }
    }
    if(arr[0] == 2 && arr[1] == 4 && arr[2] == 4){
        cout << "YES" << endl;
    }
    else if(arr[0] == 3 && arr[1] == 3 && arr[2] == 3){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}