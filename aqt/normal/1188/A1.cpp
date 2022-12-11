#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[100005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bool exist = 1;
    for(int i = 1; i<=N; i++){
        exist &= (graph[i].size() != 2);
    }
    if(exist){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}