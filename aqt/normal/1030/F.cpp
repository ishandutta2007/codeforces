#include <bits/stdc++.h>

using namespace std;

int N, Q;
long long MOD = 1e9+7;
long long arr[200005];
long long wt[200005];
long long BIT[2][200005];

void upd(int p, long long v, int t){
    for(int i = p; i<=N; i+=i&-i){
        BIT[t][i] += v;
        if(t){
            BIT[t][i] %= MOD;
            if(BIT[t][i] < 0){
                BIT[t][i] += MOD;
            }
        }
    }
}

long long query(int p, int t){
    long long ret = 0;
    for(int i = p; i; i-=i&-i){
        ret += BIT[t][i];
        if(t){
            ret %= MOD;
            if(ret < 0){
                ret += MOD;
            }
        }
    }
    return ret;
}

int binlft(long long t, int s){
    t += query(s-1, 0);
    int idx = 0;
    long long sum = 0;
    for(int i = 18; i>=0; i--){
        if(idx+(1<<i) <= N && BIT[0][idx+(1<<i)] + sum < t){
            idx += (1<<i);
            sum += BIT[0][idx];
        }
    }
    return idx+1;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        arr[i] -= i;
    }
    for(int i = 1; i<=N; i++){
        cin >> wt[i];
        upd(i, wt[i], 0);
        upd(i, wt[i]*arr[i], 1);
    }
    while(Q--){
        int x, y;
        cin >> x >> y;
        if(x < 0){
            x = -x;
            upd(x, -wt[x], 0);
            upd(x, -wt[x]*arr[x], 1);
            wt[x] = y;
            upd(x, wt[x], 0);
            upd(x, wt[x]*arr[x], 1);
        }
        else{
            long long rng = query(y, 0) - query(x-1, 0);
            int idx = binlft((rng+1)/2, x);
            long long ans = (query(idx, 0) - query(x-1, 0)) * arr[idx] - (query(idx, 1) - query(x-1, 1));
            ans += query(y, 1) - query(idx, 1) - (query(y, 0) - query(idx, 0)) * arr[idx];
            ans %= MOD;
            if(ans < 0){
                ans += MOD;
            }
            cout << ans << "\n";
        }
    }
}