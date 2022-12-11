#include <bits/stdc++.h>

using namespace std;

int T;
bool tkn[300005];
vector<int> edge;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        int N, M;
        cin >> N >> M;
        fill(tkn+1, tkn+1+3*N, 0);
        edge.clear();
        for(int i = 1; i<=M; i++){
            int u, v;
            cin >> u >> v;
            if(!tkn[u] && !tkn[v]){
                edge.push_back(i);
                tkn[u] = tkn[v] = 1;
            }
        }
        if(edge.size() >= N){
            cout << "Matching" << "\n";
            for(int i = 0; i<N; i++){
                cout << edge[i] << " ";
            }
            cout << "\n";
        }
        else{
            cout << "IndSet" << "\n";
            for(int i = 1, c = 0; i<=3*N && c<N; i++){
                if(!tkn[i]){
                    cout << i << " ";
                    c++;
                }
            }
            cout << "\n";
        }
    }
}