#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100005];
int len[100005];
long long val[12][12];
long long cnt[12][12];
long long MOD = 998244353;
long long pow10[30];
long long dgt[12][100005];

long long add(long long a, long long b){
    return (a+b)%MOD;
}

long long mult(long long a, long long b){
    return(a*b)%MOD;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    pow10[0] = 1;
    for(int i = 1; i<30; i++){
        pow10[i] = mult(pow10[i-1], 10);
    }
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        int t = arr[i];
        while(t){
            dgt[len[i]+1][i] = t%10;
            t/=10;
            len[i]++;
        }
        for(int j = 1; j<=10; j++){
            cnt[len[i]][j]++;
            for(int k = 1; k<=len[i]; k++){
                if(j > k){
                    val[len[i]][j] = add(val[len[i]][j], mult(pow10[2*k-1], dgt[k][i]));
                }
                else{
                    val[len[i]][j] = add(val[len[i]][j], mult(pow10[2*j+(k-j)-1], dgt[k][i]));
                }
            }
        }
    }
    long long ans = 0;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=10; j++){
            long long temp = 0;
            for(int k = 1; k<=len[i]; k++){
                if(j >= k){
                    temp = add(temp, mult(pow10[2*k-2], dgt[k][i]));
                }
                else{
                    temp = add(temp, mult(pow10[2*j+(k-j)-1], dgt[k][i]));
                }
            }
            temp = mult(temp, cnt[j][len[i]]);
            temp = add(temp, val[j][len[i]]);
            ans = add(ans, temp);
        }
    }
    cout << ans << endl;
}