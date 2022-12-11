#include <bits/stdc++.h>

using namespace std;

int Q, N, M;
int row[50005], col[50005];
string arr[50005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> Q;
    while(Q--){
        cin >> N >> M;
        for(int i =1; i<=N; i++){
            string s;
            cin >> s;
            for(int j= 0; j<M; j++){
                if(s[j] == '.'){
                    row[i]++;
                    col[j+1]++;
                }
            }
            arr[i] = s;
        }
        int ans = INT_MAX;
        for(int i = 1; i<=N; i++){
            for(int j = 1; j<=M; j++){
                ans = min(ans, row[i] + col[j] - (arr[i][j-1] == '.'));
            }
        }
        cout << ans << "\n";
        fill(row, row+1+N, 0);
        fill(col, col+1+M, 0);
    }
}