#include <bits/stdc++.h>

using namespace std;

long long MOD = 998244353;
long long dp1[2][20][1<<10], dp2[2][20][1<<10];
bool vis[2][20][1<<10];
long long L, R, D;
long long pow10[20];

long long add(long long a, long long b){
    return (a+b)%MOD;
}

long long mult(long long a, long long b){
    return a*b%MOD;
}

pair<long long, long long> solve(int p, long long v, int msk, bool b, bool lz){
    if(p == -1){
        return {(int) (__builtin_popcount(msk) <= D), 0};
    }
    if(!b && vis[lz][p][msk]){
        return {dp2[lz][p][msk], dp1[lz][p][msk]};
    }
    if(!b){
        vis[lz][p][msk] = 1;
    }
    int d = (b ? v/pow10[p]%10 : 9);
    auto temp = solve(p-1, v, msk|(!lz), b && d == 0, lz);
    long long cnt = temp.first;
    long long ret = temp.second;
    for(int k = 1; k<=d; k++){
        temp = solve(p-1, v, msk|(1<<k), b && d == k, 0);
        ret = add(ret, mult(temp.first, mult(pow10[p], k)) + temp.second);
        cnt = add(cnt, temp.first);
    }
    if(!b){
        dp1[lz][p][msk] = ret;
        dp2[lz][p][msk] = cnt;
    }
    return {cnt, ret};
}

int main(){
    pow10[0] = 1;
    for(int d = 1; d<19; d++){
        pow10[d] = pow10[d-1] * 10;
    }
    cin >> L >> R >> D;
    cout << ((solve(18, R, 0, 1, 1).second - solve(18, L-1, 0, 1, 1).second)%MOD + MOD)%MOD <<endl;
}