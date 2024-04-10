#include <bits/stdc++.h>

using namespace std;

struct state{
    short x, y, k;
};

int N, M, K;
short arr[1005][1005];
int sp[10];
int mx[4], my[4];
int ans[11];
state ll[1000005], temp[1000005];
int lll = 1, llr = 0, tl = 1, tr = 0;
string t;

int main(){
    cin >> N >> M >> K;
    for(int i = 1; i<=K; i++){
        cin >> sp[i];
        sp[i] = min(N+M, sp[i]);
    }
    fill(arr[0], arr[0]+M+2, 10);
    fill(arr[N+1], arr[N+1]+M+2, 10);
    for(int i = 1; i<=N; i++){
        arr[i][0] = 10;
        cin >> t;
        for(int j = 0; j<M; j++){
            if(t[j] == '#'){
                arr[i][j+1] = 10;
            }
            else if(t[j] == '.'){
                arr[i][j+1] = 0;
            }
            else{
                arr[i][j+1] = t[j]-'0';
            }
        }
        arr[i][M+1] = 10;
    }
    for(int k = 1; k<=K; k++){
        for(int i = 1; i<=N; i++){
            for(int j = 1; j<=M; j++){
                if(arr[i][j] == k){
                    ll[++llr] = {i, j, sp[k]};
                }
            }
        }
    }
    mx[0] = 1;
    mx[1] = -1;
    my[2] = -1;
    my[3] = 1;
    while(llr >= lll){
        state s = ll[lll];
        while(arr[ll[lll].x][ll[lll].y] == arr[s.x][s.y]){
            temp[++tr] = (ll[lll++]);
        }
        while(tr >= tl){
            s = temp[tl++];
            for(int i = 0; i<4; i++){
                if(!arr[mx[i]+s.x][my[i]+s.y]){
                    arr[mx[i]+s.x][my[i]+s.y] = arr[s.x][s.y];
                    if(s.k == 1){
                        ll[++llr] = {mx[i]+s.x, my[i]+s.y, sp[arr[s.x][s.y]]};
                    }
                    else{
                        temp[++tr] = {mx[i]+s.x, my[i]+s.y, s.k-1};
                    }
                }
            }
        }
    }
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=M; j++){
            ans[arr[i][j]]++;
        }
    }
    for(int i = 1; i<=K; i++){
        cout << ans[i] << " ";
    }
}