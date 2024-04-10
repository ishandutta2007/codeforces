#include <bits/stdc++.h>

using namespace std;

int N, Q, BLKSZ = 800, B;
multiset<long long> blk[650];
long long offset[650];
long long arr[500005];

void upd(int l, int r, int v){
    while(l <= r && l%BLKSZ){
        blk[l/BLKSZ].erase(blk[l/BLKSZ].find(arr[l]));
        arr[l] += v;
        blk[l/BLKSZ].insert(arr[l]);
        l++;
    }
    while(l + BLKSZ <= r){
        offset[l/BLKSZ]+=v;
        l += BLKSZ;
    }
    while(l <= r){
        blk[l/BLKSZ].erase(blk[l/BLKSZ].find(arr[l]));
        arr[l] += v;
        blk[l/BLKSZ].insert(arr[l]);
        l++;
    }
}

int query(long long x){
    int lft = 1, rht = 0;
    bool f = 1;
    for(int i = 0; i<B && f; i++){
        if(blk[i].count(x-offset[i])){
            for(int j = i*BLKSZ; f;j++){
                if(arr[j] == x-offset[i]){
                    lft = j;
                    f = 0;
                }
            }
        }
    }
    f = 1;
    for(int i = B-1; i>=0 && f; i--){
        if(blk[i].count(x-offset[i])){
            for(int j = (i+1)*BLKSZ-1; f;j--){
                if(arr[j] == x-offset[i]){
                    rht = j;
                    f = 0;
                }
            }
        }
    }
    return rht-lft;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    B = (N+BLKSZ-1)/BLKSZ;
    for(int i = 0; i<N; i++){
        cin >> arr[i];
        blk[i/BLKSZ].insert(arr[i]);
    }
    while(Q--){
        int c;
        cin >> c;
        if(c == 1){
            int l, r, v;
            cin >> l >> r >> v;
            l--;
            r--;
            upd(l ,r, v);
        }
        else{
            int n;
            cin >> n;
            cout << query(n) << "\n";
        }
    }
}