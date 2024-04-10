#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[200005];
vector<pair<int, int>> srt;
long long BIT[200005][2];

void upd(int n, int v, int t){
    for(int i = n; i<=N; i+=i&-i){
        BIT[i][t] += v;
    }
}

int query(int n){
    int ret = 0;
    for(int i = n; i>0; i-=i&-i){
        ret += BIT[i][1];
    }
    return ret;
}

int clmb(int t){
    int idx = 0;
    long long s = 0;
    for(int b = 19; b>=0; b--){
        if(idx + (1<<b) <= N && BIT[idx+(1<<b)][0] + s <= t){
            idx += (1<<b);
            s += BIT[idx][0];
            //cout << "sum: " << s << endl;
        }
    }
    return idx;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        srt.push_back({arr[i], i});
    }
    sort(srt.begin(), srt.end());
    for(int i = 1; i<=N; i++){
        //cout << "idx: " << i << endl;
        //cout << clmb(M-arr[i]) << endl;
        cout << (i-query(clmb(M-arr[i]))-1) << " ";
        int idx = lower_bound(srt.begin(), srt.end(), make_pair(arr[i], i)) - srt.begin() + 1;
        //cout << idx << endl;
        upd(idx, arr[i], 0), upd(idx, 1, 1);
    }
}