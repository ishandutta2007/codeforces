#include <bits/stdc++.h>

using namespace std;

int K, N = 1000;
int cnt = 2;
char graph[1005][1005];
int bits[1005];

int main(){
    cin >> K;
    for(int i =1 ; i<=N; i++){
        for(int j= 1; j<=N; j++){
            graph[i][j] = 'N';
        }
    }
    if(K == 1){
        cout << 2 << endl;
        graph[1][2] = graph[2][1] = 'Y';
        cout << graph[1][1] << graph[1][2] << endl;
        cout << graph[1][2] << graph[2][2] << endl;
        return 0;
    }
    int h = 31 - __builtin_clz(K);
    bits[h] = 1;
    for(int i = h-1; i>=0; i--){
        cnt++;
        graph[bits[i+1]][cnt] = graph[cnt][bits[i+1]] = 'Y';
        cnt++;
        graph[bits[i+1]][cnt] = graph[cnt][bits[i+1]] = 'Y';
        cnt++;
        graph[cnt-2][cnt] = graph[cnt][cnt-2] = 'Y';
        graph[cnt-1][cnt] = graph[cnt][cnt-1] = 'Y';
        bits[i] = cnt;
        if((1<<i)&K){
            int lst = 1;
            for(int k = 0; k<2*(h-i)-1; k++){
                cnt++;
                graph[lst][cnt] = graph[cnt][lst] = 'Y';
                lst = cnt;
            }
            graph[lst][bits[i]] = graph[bits[i]][lst] = 'Y';
        }
    }
    graph[bits[0]][2] = graph[2][bits[0]] = 'Y';
    cout << cnt << "\n";
    for(int i =1; i<=cnt; i++){
        for(int j = 1; j<=cnt; j++){
            cout << graph[i][j];
        }
        cout << "\n";
    }
}