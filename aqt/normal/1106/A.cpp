#include <bits/stdc++.h>

using namespace std;

char arr[501][501];
int N;
string s;

int main(){
    cin >> N;
    for(int i =1; i<=N; i++){
        cin >> s;
        for(int j = 1; j<=N; j++){
            arr[i][j] = s[j-1];
        }
    }
    int cnt = 0;
    for(int i = 2; i<N; i++){
        for(int j = 2; j<N; j++){
            if(arr[i-1][j-1] == 'X' && arr[i][j] == 'X' && arr[i-1][j+1] == 'X'
               && arr[i+1][j-1] =='X' && arr[i+1][j+1] == 'X'){
                cnt++;
               }
        }
    }
    cout << cnt << endl;
}