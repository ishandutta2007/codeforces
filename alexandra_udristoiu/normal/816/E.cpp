#include<iostream>
#include<vector>
using namespace std;
int n, i, x, b, j;
int num[5005], num2[5005], c[5005], c2[5005], d[2][5005][5005];
vector<int> v[5005];
void dfs2(int nod){
    num2[nod] = 1;
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        dfs2(vecin);
        num2[nod] += num2[vecin];
    }
}
void dfs(int nod){
    num[nod] = 1;
    d[0][nod][0] = d[1][nod][1] = 0;
    d[0][nod][1] = c[nod];
    int i, vecin, j, ii;
    for(i = 0; i < v[nod].size(); i++){
        vecin = v[nod][i];
        dfs(vecin);
        num[nod] += num[vecin];
        for(j = num[nod]; j >= 1; j--){
            for(ii = max(0, j - num[vecin]); ii <= min(j - 1, num[nod] - num[vecin]); ii++){
                d[0][nod][j] = min(d[0][nod][j], d[0][nod][ii] + d[0][vecin][j - ii]);
                if(ii != 0){
                    d[1][nod][j] = min(d[1][nod][j], d[1][nod][ii] + min(d[0][vecin][j - ii], d[1][vecin][j - ii]));
                }
            }
        }
    }
    for(i = 1; i <= num[nod]; i++){
        d[1][nod][i] += c[nod] - c2[nod];
    }
}
int main(){
    cin>> n >> b;
    for(i = 1; i <= n; i++){
        cin>> c[i] >> c2[i];
        if(i >= 2){
            cin>> x;
            v[x].push_back(i);
        }
    }
    dfs2(1);
    for(i = 1; i <= n; i++){
        for(j = 0; j <= num2[i]; j++){
            d[0][i][j] = d[1][i][j] = 1000000005;
        }
    }
    dfs(1);
    for(i = n; i >= 0; i--){
        if(min(d[0][1][i], d[1][1][i]) <= b){
            cout<< i;
            return 0;
        }
    }
}