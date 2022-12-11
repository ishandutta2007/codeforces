#include <bits/stdc++.h>

using namespace std;

int N, Q;
int bss[20][500005];
int arr[500005];
pair<int, int> qu[500005];
int ans[500005];

void upd(int idx, int nxt, int v = -1){
    int t = v;
    if(t == -1){
        t = arr[idx];
    }
    for(int b = 19; b>=0; b--){
        if(t&(1<<b)){
            if(!bss[b][idx]){
                bss[b][idx] = t;
            }
            t ^= bss[b][idx];
        }
        bss[b][nxt] = bss[b][idx];
    }
}

void solve(int l, int r, vector<int> v){
    if(v.empty() || l > r){
        return;
    }
    int mid = l + r >> 1;
    vector<int> lft, rht;
    for(int b = 0; b<20; b++){
        bss[b][mid+1] = bss[b][mid] = 0;
    }
    for(int i = mid+1; i<=r; i++){
        upd(i, i+1);
    }
    for(int i = mid; i>=l; i--){
        upd(i, i-1);
    }
    for(int q : v){
        if(qu[q].second < mid){
            lft.push_back(q);
        }
        else if(qu[q].first > mid+1){
            rht.push_back(q);
        }
        else{
            for(int b = 0; b<20; b++){
                bss[b][N+2] = 0;
            }
            for(int b = 19; b>=0; b--){
                upd(N+2, N+2, bss[b][qu[q].second]);
                upd(N+2, N+2, bss[b][qu[q].first]);
            }
            for(int b = 19; b>=0; b--){
                if(!(ans[q]&(1<<b))){
                    ans[q] ^= bss[b][N+2];
                }
            }
        }
    }
    solve(l, mid-1, lft);
    solve(mid+2, r, rht);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    cin >> Q;
    vector<int> v;
    for(int i = 1; i<=Q; i++){
        cin >> qu[i].first >> qu[i].second;
        v.push_back(i);
    }
    solve(1, N, v);
    for(int q = 1; q<=Q; q++){
        cout << ans[q] << "\n";
    }
}