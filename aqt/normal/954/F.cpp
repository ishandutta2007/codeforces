#include <bits/stdc++.h>

using namespace std;

int N;
long long M;
long long mat[3][3][20];
long long MOD = 1e9+7;
long long lft[10005], rht[10005], typ[10005], cnt[3];
vector<pair<long long, int>> v;

long long sig(long long a){
    if(a < 0){
        return -1;
    }
    else if(a == 0){
        return 0;
    }
    else{
        return 1;
    }
}

void cop(int p, int q){
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            mat[i][j][p] = mat[i][j][q];
        }
    }
}

void mult(int p, int a, int b){
    for(int i = 0; i<3; i++){
        for(int j= 0; j<3; j++){
            mat[i][j][p] = 0;
            for(int k = 0; k<3; k++){
                mat[i][j][p] += mat[i][k][a] * mat[k][j][b];
                mat[i][j][p] %= MOD;
            }
        }
    }
}

void solve(long long e, int msk){
    if(!e){
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                if(i != j){
                    mat[i][j][9] = 0;
                }
                else{
                    mat[i][j][9] = 1;
                }
            }
        }
        return;
    }
    solve(e/2, msk);
    mult(10, 9, 9);
    cop(9, 10);
    if(e&1){
        mult(10, 9, msk);
        cop(9, 10);
    }
}

int main(){
    for(int m = 0; m<8; m++){
        for(int i = 0; i<3; i++){
            if((1<<i)&m){
                for(int j = 0; j<3; j++){
                    if((1<<j)&m && abs(i-j) <= 1){
                        mat[i][j][m] = 1;
                    }
                }
            }
        }
    }
    mat[0][0][8] = mat[1][1][8] = mat[2][2][8] = 1;
    cin >> N >> M;
    for(int i = 1; i<=N; i++){
        cin >> typ[i] >> lft[i] >> rht[i];
        typ[i]--;
        v.push_back({lft[i], i});
        v.push_back({rht[i], -i});
    }
    sort(v.begin(), v.end());
    long long lst = 1;
    int m = 0, idx = 0;
    while(idx < v.size()){
        long long c = v[idx].first;
        solve(c - lst, m^7);
        mult(10, 8, 9);
        cop(8, 10);
        lst = c;
        while(idx < v.size() && v[idx].first == c){
            cnt[typ[abs(v[idx].second)]] += sig(v[idx].second);
            idx++;
        }
        m = 0;
        for(int i = 0; i<3; i++){
            if(cnt[i]){
                m |= 1<<i;
            }
        }
    }
    solve(M - lst, 7);
    mult(10, 8, 9);
    cop(8, 10);
    cout << mat[1][1][8] << endl;
}