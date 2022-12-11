#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> vec;
bool mp[55][55];
queue<int> X, Y;
int sX, sY, eX, eY;
string s;
int cmp[55][55];
int mo[4][2] = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};

int main(){
    cin >> N >> sX >> sY >> eX >> eY;
    for(int i = 1; i<=N; i++){
        cin >> s;
        for(int j = 1; j<=N; j++){
            mp[i][j] = s[j-1] == '0';
        }
    }
    X.push(sX);
    Y.push(sY);
    cmp[sX][sY] = 1;
    while(X.size()){
        int x = X.front(), y = Y.front();
        X.pop();
        Y.pop();
        for(int m = 0; m<4; m++){
            if(mp[x+mo[m][0]][y+mo[m][1]] && !cmp[x+mo[m][0]][y+mo[m][1]]){
                cmp[x+mo[m][0]][y+mo[m][1]] = 1;
                X.push(x+mo[m][0]);
                Y.push(y+mo[m][1]);
            }
        }
    }
    if(cmp[eX][eY]){
        cout << 0 << endl;
        return 0;
    }
    X.push(eX);
    Y.push(eY);
    cmp[eX][eY] = 2;
    long long ans = LLONG_MAX/2;
    while(X.size()){
        int x = X.front(), y = Y.front();
        for(int i= 1; i<=N; i++){
            for(int j = 1; j<=N; j++){
                if(cmp[i][j] == 1){
                    ans = min(ans, 1LL*(x-i)*(x-i)+1LL*(y-j)*(y-j));
                }
            }
        }
        X.pop();
        Y.pop();
        for(int m = 0; m<4; m++){
            if(mp[x+mo[m][0]][y+mo[m][1]] && !cmp[x+mo[m][0]][y+mo[m][1]]){
                cmp[x+mo[m][0]][y+mo[m][1]] = 2;
                X.push(x+mo[m][0]);
                Y.push(y+mo[m][1]);
            }
        }
    }
    cout << ans << endl;
}