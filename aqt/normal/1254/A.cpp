#include <bits/stdc++.h>

using namespace std;

int T, N, M, K;
vector<char> v[20005];
vector<char> c;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(char k = 'a'; k<='z'; k++){
        c.push_back(k);
    }
    for(char k = 'A'; k<='Z'; k++){
        c.push_back(k);
    }
    for(char k = '0'; k<='9'; k++){
        c.push_back(k);
    }
    cin >> T;
    while(T--){
        cin >> N >> M >> K;
        int cnt = 0;
        for(int i = 0; i<N; i++){
            v[i].resize(M);
            for(int j = 0; j<M; j++){
                cin >> v[i][j];
                cnt += v[i][j] == 'R';
            }
        }
        int idx = 0, lft = cnt, m = cnt%K;
        for(int n = 0; n<K-1; n++){
            char t = c[n];
            int amt = cnt/K + (n < m);
            lft -= cnt/K + (n < m);
            while(amt){
                int i = idx/M, j = idx%M;
                if(i%2 == 0){
                    j = M-j-1;
                }
                amt -= v[i][j] =='R';
                v[i][j] = t;
                idx++;
            }
        }
        while(idx < N*M){
            int i = idx/M, j = idx%M;
            if(i%2 == 0){
                j = M-j-1;
            }
            v[i][j] = c[K-1];
            idx++;
        }
        for(int i =0 ; i<N; i++){
            for(int j = 0; j<M; j++){
                cout << v[i][j];
            }
            cout << "\n";
        }
    }
}