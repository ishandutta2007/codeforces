#include <bits/stdc++.h>

using namespace std;

int N, K;
string s;
queue<int> qu;
int dist[200005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K >> s;
    fill(dist, dist+1+N, INT_MAX);
    for(int i = 0; i<N; i++){
        if(s[i] == s[(i-1+N)%N] || s[i] == s[(i+1)%N]){
            dist[i] = 0;
            qu.push(i);
        }
    }
    while(qu.size()){
        int n = qu.front();
        //cout << n << " " << dist[n] << endl;
        qu.pop();
        if(dist[n] == K){
            break;
        }
        if(dist[(n+1)%N] > dist[n] + 1){
            dist[(n+1)%N] = dist[n] + 1;
            s[(n+1)%N] = s[n];
            qu.push((n+1)%N);
        }
        if(dist[(n-1+N)%N] > dist[n] + 1){
            dist[(n-1+N)%N] = dist[n] + 1;
            s[(n-1+N)%N] = s[n];
            qu.push((n-1+N)%N);
        }
    }
    if(K%2 == 1){
        for(int i = 0; i<N; i++){
            if(dist[i] == INT_MAX){
                if(s[i] == 'W'){
                    s[i] = 'B';
                }
                else{
                    s[i] = 'W';
                }
            }
        }
    }
    for(int i = 0; i<N; i++){
        cout << s[i];
    }
}