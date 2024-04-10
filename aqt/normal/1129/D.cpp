#include <bits/stdc++.h>

using namespace std;

int N, B = 350, K, C = 500;
int delta[1005];
long long tbl[1005][1005];
int lst1[100005], lst2[100005];
int val[100005];
long long dp[100005];
long long MOD = 998244353;

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

void build(int b){
    int l = b*B, r = (b+1)*B-1;
    int sum = 0;
    for(int k = -B+C; k<=B+C; k++){
        tbl[b][k] = 0;
    }
    for(int i = r; i>=l; i--){
        sum += val[i];
        tbl[b][sum+C] += dp[i];
        //cout << "v: " << val[i] << endl;
    }
    for(int k = -B+C+1; k<=B+C; k++){
        tbl[b][k] = add(tbl[b][k], tbl[b][k-1]);
    }
    delta[b] = sum;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    fill(lst1+1, lst1+N+1, -1);
    fill(lst2+1, lst2+N+1, -1);
    dp[0] = 1;
    for(int i = 0; i<N; i++){
        int n;
        cin >> n;
        val[i] = 1;
        if(lst1[n]+1){
            val[lst1[n]] = -1;
            if(lst1[n] < i/B*B){
                build(lst1[n]/B);
            }
        }
        if(lst2[n]+1){
            val[lst2[n]] = 0;
            if(lst2[n] < i/B*B) {
                build(lst2[n]/B);
            }
        }
        lst2[n] = lst1[n];
        lst1[n] = i;
        int j = i, tot = 0;
        do{
            tot += val[j];
            if(tot <= K){
                dp[i+1] = add(dp[i+1], dp[j]);
            }
            j--;
        }
        while(j%B != B-1 && j%B != -1);
        //cout << i << " " << j << " " << dp[i+1] << endl;
        if(j >= 0){
            j /= B;
            while(j >= 0){
                int temp = K - tot;
                //cout << " " << i << " " << temp << endl;
                if(temp < -B);
                else{
                    dp[i+1] = add(dp[i+1], tbl[j][min(B+C, temp+C)]);
                }
                tot += delta[j];
                j--;
            }
        }
        //cout << i << " " << dp[i+1] << endl;
        if(i%B == B-1){
            build(i/B);
        }
    }
    cout << dp[N] << endl;
}