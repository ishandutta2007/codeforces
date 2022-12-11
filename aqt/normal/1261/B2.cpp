#include <bits/stdc++.h>

using namespace std;

int N, Q;
int arr[200005];
int BIT[200005];
int ans[200005];
int pos[200005], k[200005];
vector<pair<int, int>> v, a;

void upd(int n){
    for(int i = n; i<=N; i+=i&-i){
        BIT[i]++;
    }
}

int query(int n){
    int ret = 0;
    for(int i = n; i; i-=i&-i){
        ret += BIT[i];
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        a.push_back({arr[i], -i});
    }
    cin >> Q;
    for(int q = 1; q<=Q; q++){
        cin >> k[q] >> pos[q];
        v.push_back({k[q], q});
    }
    sort(a.begin(), a.end(), greater<pair<int, int>>());
    sort(v.begin(), v.end());
    int idx = 0;
    for(int i = 0; i<N; i++){
        //cout << i << " " << -a[i].second << endl;
        upd(-a[i].second);
        while(idx < v.size() && v[idx].first == i+1){
            int n = v[idx].second;
            int l = 1, r = N;
            while(l <= r){
                int mid = l+r>>1;
                if(query(mid) >= pos[n]){
                    ans[n] = arr[mid];
                    r = mid - 1;
                }
                else{
                    l = mid+1;
                }
            }
            idx++;
        }
    }
    for(int q = 1; q<=Q; q++){
        cout << ans[q] << "\n";
    }
}