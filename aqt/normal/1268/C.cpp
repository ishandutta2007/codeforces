#include <bits/stdc++.h>

using namespace std;

int N;
int arr[200005];
int pos[200005];
long long inv[200005];
long long BIT[3][200005];

long long query(int t, int p){
    long long ret = 0;
    for(int i = p; i; i-=i&-i){
        ret += BIT[t][i];
    }
    return ret;
}

void upd(int t, int p, int v){
    for(int i = p; i<=N; i+=i&-i){
        BIT[t][i] += v;
    }
}

int clmb(int t, long long n){
    int ret = 0;
    long long sum = 0;
    for(int k = 17; k>=0; k--){
        if((1<<k)+ret <= N && BIT[t][ret+(1<<k)] + sum < n){
            sum += BIT[t][ret+(1<<k)];
            ret += (1<<k);
        }
    }
    return ret+1;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin>> arr[i];
        pos[arr[i]] = i;
    }
    for(int i = N; i; i--){
        inv[arr[i]] = query(0, arr[i]);
        upd(0, arr[i], 1);
    }
    for(int i = 1; i<=N; i++){
        inv[i] += inv[i-1];
    }
    for(int i = 1; i<=N; i++){
        long long mid = (i+1)/2;
        upd(1, pos[i], 1);
        long long idx = clmb(1, mid);
        //cout << "idx: " << idx << endl;
        upd(2, pos[i], pos[i]);
        long long out = idx*mid - query(2, idx) - mid*(mid-1)/2;
        //cout << out << endl;
        out += query(2, N) - query(2, idx) - idx*(i-mid) - (i-mid)*(i-mid+1)/2;
        //cout << " " << idx*(i-mid) << endl;
        //cout << out << endl;
        out += inv[i];
        cout << out << " ";
    }
}