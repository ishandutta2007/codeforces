#include <bits/stdc++.h>

using namespace std;

char arr[20][20];

bool chk(int x, int y){
    int cnt = 0;
    for(int i = x; i<x+5; i++){
        if(arr[i][y] != 'X'){
            break;
        }
        cnt++;
    }
    for(int i = x-1; i>x-5; i--){
        if(arr[i][y] != 'X'){
            break;
        }
        cnt++;
    }
    if(cnt >= 5){
        return true;
    }
    cnt = 0;
    for(int i = y; i<y+5; i++){
        if(arr[x][i] != 'X'){
            break;
        }
        cnt++;
    }
    for(int i = y-1; i>y-5; i--){
        if(arr[x][i] != 'X'){
            break;
        }
        cnt++;
    }
    if(cnt >= 5){
        return true;
    }
    cnt = 0;
    for(int i = 0; i<5; i++){
        if(arr[x-i][y-i] != 'X'){
            break;
        }
        cnt++;
    }
    for(int i = 1; i<5; i++){
        if(arr[x+i][y+i] != 'X'){
            break;
        }
        cnt++;
    }
    if(cnt >= 5){
        return true;
    }
    cnt = 0;
    for(int i =0 ; i<5; i++){
        if(arr[x-i][y+i] != 'X'){
            break;
        }
        cnt++;
    }
    for(int i = 1; i<5; i++){
        if(arr[x+i][y-i] != 'X'){
            break;
        }
        cnt++;
    }
    if(cnt >= 5){
        return true;
    }
    return false;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 5; i<15; i++){
        string s;
        cin >> s;
        for(int j = 5; j<15; j++){
            arr[i][j] = s[j-5];
        }
    }
    for(int i = 5; i<15; i++){
        for(int j = 5; j<15; j++){
            if(arr[i][j] != 'X' && arr[i][j] != 'O'){
                arr[i][j] = 'X';
                if(chk(i, j)){
                    cout << "YES" << endl;
                    return 0;
                }
                arr[i][j] = '.';
            }
        }
    }
    cout << "NO" << endl;
}