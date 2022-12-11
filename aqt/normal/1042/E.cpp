#include <bits/stdc++.h>

using namespace std;

int N, M;
long long MOD = 998244353;
int arr[1005][1005];
pair<int, pair<int, int>> srt[1000005];
long long dp[1005][1005];

long long add(long long a, long long b){
    return (a+b)%MOD;
}

long long sub(long long a, long long b){
    a = add(a, -b);
    if(a < 0){
        a += MOD;
    }
    return a;
}

long long mult(long long a, long long b){
    return (a*b)%MOD;
}

long long qikpow(long long b, long long e){
    if(!e){
        return 1;
    }
    long long ret = qikpow(b, e/2);
    ret = mult(ret, ret);
    if(e%2){
        ret = mult(ret, b);
    }
    return ret;
}

long long divd(long long a, long long b){
    return mult(a, qikpow(b, MOD-2));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int idx = 0;
    for(int i= 1; i<=N; i++){
        for(int j = 1; j<=M; j++){
            cin >> arr[i][j];
            srt[++idx] = {arr[i][j], {i, j}};
        }
    }
    sort(srt+1, srt+N*M+1);
    long long sumev = 0, sumri = 0, sumrisqr = 0, sumci = 0, sumcisqr = 0, sz = 0;
    for(int i = 1; i<=N*M; ){
        for(int j = i; j<=N*M; j++){
            if(srt[i].first != srt[j].first){
                break;
            }
            int x = srt[j].second.first, y = srt[j].second.second;
            if(sz){
                dp[x][y] = sub(sumrisqr+sumcisqr+sumev, add(mult(2*sumri, x), mult(2*sumci, y)));
                dp[x][y] = divd(dp[x][y], sz);
                dp[x][y] = add(dp[x][y], add(mult(x, x), mult(y, y)));
            }
            //cout << x << " " << y << " " << dp[x][y] << endl;
        }
        int s = i;
        for(; i<=N*M; i++){
            if(srt[s].first != srt[i].first){
                break;
            }
            int x = srt[i].second.first, y = srt[i].second.second;
            sz++;
            sumri = add(sumri, x), sumci = add(sumci, y);
            sumrisqr = add(sumrisqr, mult(x, x)), sumcisqr = add(sumcisqr, mult(y, y));
            sumev = add(dp[x][y], sumev);
        }
    }
    int Sx, Sy;
    cin >> Sx >> Sy;
    cout << dp[Sx][Sy] << endl;
}