#include <bits/stdc++.h>

using namespace std;

int graph[3][3];

int main(){
    int K;
    cin >> K;
    for(int i = 0; i<3; i++){
        for(int j = i+1; j<3; j++){
            cin >> graph[i][j];
            graph[j][i] = graph[i][j];
        }
    }
    int n = 0;
    K--;
    int tot = 0;
    while(K--){
        if(graph[n][(n+1)%3] < graph[n][(n+2)%3]){
            tot += graph[n][(n+1)%3];
            n = (n+1)%3;
        }
        else{
            tot += graph[n][(n+2)%3];
            n = (n+2)%3;
        }
    }
    cout << tot << endl;
}