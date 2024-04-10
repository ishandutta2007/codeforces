#include <bits/stdc++.h>

using namespace std;

string s;
int dist[10][10];
int ans[10][10];
deque<int> dq;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            if(i > j){
                ans[i][j] = ans[j][i];
                continue;
            }
            for(int d = 0;d <10; d++){
                for(int b = 0; b<10; b++){
                    dist[d][b] = 100;
                }
            }
            for(int d1 = 0; d1<10; d1++){
                dist[d1][d1] = 0;
                dq.push_back(d1);
                bool b = 1;
                while(dq.size()){
                    int n = dq.front();
                    dq.pop_front();
                    int v = dist[d1][n];
                    if(b){
                        dist[d1][d1] = 100;
                        b = 0;
                    }
                    if(dist[d1][(n+i)%10] > v + 1){
                        dist[d1][(n+i)%10] = v + 1;
                        dq.push_back((n+i)%10);
                    }
                    if(dist[d1][(n+j)%10] > v + 1){
                        dist[d1][(n+j)%10] = v + 1;
                        dq.push_back((n+j)%10);
                    }

                }
            }
            for(int k = 1; k<s.size(); k++){
                int db = s[k-1] - '0', da = s[k] - '0';
                if(dist[db][da] == 100){
                    ans[i][j] = -1;
                    break;
                }
                ans[i][j] += dist[db][da];
            }
        }
    }
    int si = s.size();
    for(int i = 0; i<10 ;i++){
        for(int j =0; j<10; j++){
            int out = ans[i][j];
            if(out != -1){
                out -= si - 1;
            }
            cout << out << " ";
        }
        cout << "\n";
    }
}