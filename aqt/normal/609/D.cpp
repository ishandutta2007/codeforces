#include <bits/stdc++.h>

using namespace std;

int N, M, K;
long long S;
long long a[200005], b[200005];
pair<long long, int> arr[200005], brr[200005];
int idx1, idx2;
int ans = -1;
vector<pair<int, int>> lst;

bool solve(int n){
    long long ba = INT_MAX, bb = INT_MAX;
    long long baidx = 0, bbidx = 0;
    for(int i = 1; i<=n; i++){
        if(ba > a[i]){
            baidx = i;
            ba = a[i];
        }
        if(bb > b[i]){
            bbidx = i;
            bb = b[i];
        }
    }
    long long sum1 = 0, sum2 = 0;
    for(int i= 1; i<=idx2; i++){
        sum2 += brr[i].first;
    }
    int crnt = idx2;
    for(int i = 0; i<=idx1; i++){
        sum1 += arr[i].first;
        while(crnt && sum1*ba + sum2*bb > S){
            sum2 -= brr[crnt--].first;
        }
        if(i+crnt >= K && sum1*ba + sum2*bb <= S){
            ans = n;
            lst.clear();
            for(int j = 1; j<=i; j++){
                lst.push_back({arr[j].second, baidx});
            }
            for(int j = 1; j<=crnt; j++){
                lst.push_back({brr[j].second, bbidx});
            }
            return 1;
        }
    }
    return 0;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K >> S;
    for(int i= 1; i<=N; i++){
        cin >> a[i];
    }
    for(int i = 1; i<=N; i++){
        cin >> b[i];
    }
    for(int i= 1; i<=M; i++){
        int t, c;
        cin >> t >> c;
        if(t == 1){
            arr[++idx1] = {c, i};
        }
        else{
            brr[++idx2] = {c, i};
        }
    }
    sort(arr+1, arr+1+idx1);
    sort(brr+1, brr+1+idx2);
    int l = 1, r = N;
    while(l <= r){
        int mid = l+r>>1;
        if(solve(mid)){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << ans << "\n";
    for(auto p : lst){
        cout << p.first << " " << p.second << "\n";
        K--;
        if(!K){
            break;
        }
    }
}