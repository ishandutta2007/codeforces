#include <bits/stdc++.h>

using namespace std;

int N, M, B = 600;
vector<int> cmp;
int fx[200005], ans[200005];
long long len[200005];
int pos[200005], val[200005], endpt[200005];
bool eaten[200005];
int arr[400005], blk[700];
queue<int> v[400005], blkv[700];

int getpos(long long p){
    if(p > 1000000000){
        return cmp.end()-cmp.begin();
    }
    return lower_bound(cmp.begin(), cmp.end(), (int) (p)) - cmp.begin();
}

void upd(int l, int r, int idx){
    while(l <= r){
        while(l <= r){
            if(!arr[l] || fx[arr[l]] > fx[idx]){
                arr[l] = idx;
            }
            while(v[l].size()){
                int m = v[l].front();
                v[l].pop();
                if(!eaten[m]){
                    len[idx] += val[m];
                    eaten[m] = 1;
                    r = getpos(fx[idx]+len[idx]+1)-1;
                    ans[idx]++;
                }
            }
            l++;
            if(l%B == 0){
                break;
            }
        }
        while(l+B-1 <= r){
            int k = l/B;
            if(!blk[k] || fx[blk[k]] > fx[idx]){
                blk[k] = idx;
            }
            while(blkv[k].size()){
                int m = blkv[k].front();
                blkv[k].pop();
                if(!eaten[m]){
                    len[idx] += val[m];
                    eaten[m] = 1;
                    r = getpos(fx[idx]+len[idx]+1)-1;
                    ans[idx]++;
                }
            }
            l += B;
        }
    }
    endpt[idx] = max(r, endpt[idx]);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    fx[0] = INT_MAX;
    for(int i = 1; i<=N; i++){
        cin >> fx[i] >> len[i];
        cmp.push_back(fx[i]);
    }
    for(int i = 1; i<=M; i++){
        cin >> pos[i] >> val[i];
        cmp.push_back(pos[i]);
    }
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    for(int i = 1; i<=N; i++){
        int p = getpos(fx[i]);
        endpt[i] = p;
        upd(endpt[i], getpos(fx[i]+len[i]+1)-1, i);
    }
    for(int m = 1; m<=M; m++){
        int p = getpos(pos[m]);
        int f = (fx[blk[p/B]] < fx[arr[p]] ? blk[p/B] : arr[p]);
        if(!f){
            v[p].push(m);
            blkv[p/B].push(m);
            continue;
        }
        ans[f]++;
        len[f] += val[m];
        upd(endpt[f], getpos(fx[f]+len[f]+1)-1, f);
    }
    for(int i = 1; i<=N; i++){
        cout << ans[i] << " " << len[i] << "\n";
    }
}