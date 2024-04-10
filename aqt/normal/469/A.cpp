#include <bits/stdc++.h>

using namespace std;

int arr[101];

int main(){
    int N;
    cin >> N;
    int cnt = 0;
    int X;
    cin >> X;
    for(int i= 1; i<=X; i++){
        int n;
        cin >> n;
        if(!arr[n]){
            arr[n] = 1;
            cnt++;
        }
    }
    cin >> X;
    for(int i= 1; i<=X; i++){
        int n;
        cin >> n;
        if(!arr[n]){
            arr[n] = 1;
            cnt++;
        }
    }
    if(cnt == N){
        cout << "I become the guy." << endl;
    }
    else{
        cout << "Oh, my keyboard!" << endl;
    }
}