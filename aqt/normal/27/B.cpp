#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[55];
int out[55];
deque<int> dq;
vector<int> ord;
bool game[55][55];

int main(){
    cin >> N;
    for(int i = 1; i<N*(N-1)/2; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        out[b]++;
        game[a][b] = game[b][a] = 1;
    }
    for(int i = 1; i<=N; i++){
        if(!out[i]){
            dq.push_back(i);
        }
    }
    while(dq.size()){
        int n = dq.front();
        dq.pop_front();
        ord.push_back(n);
        for(int e : graph[n]){
            out[e]--;
            if(!out[e]){
                dq.push_back(e);
            }
        }
    }
    int p1 = 0, p2 = 0;
    for(int i =1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            if(!game[i][j] && i != j){
                p1 = i;
                p2 = j;
                break;
            }
        }
    }
    if(find(ord.begin(), ord.end(), p1)-ord.begin() < find(ord.begin(), ord.end(), p2)-ord.begin()){
        cout << p1 << " " << p2 << endl;
    }
    else{
        cout << p2 << " " << p1 << endl;
    }
}