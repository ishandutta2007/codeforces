#include <bits/stdc++.h>

using namespace std;

int blksz = 300;

struct query{
    int l, r, id;
    bool operator < (query q) const{
        if(l/blksz == q.l/blksz){
            return r < q.r;
        }
        return l/blksz < q.l/blksz;
    }
};

int N, Q;
int arr[100005];
int fre[100005];
int ans[100005];
query qu[100005];

int main(){
    cin >> N >> Q;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    int l = 1, r = 0;
    for(int i = 1; i<=Q; i++){
        int l, r;
        cin >> l >> r;
        qu[i] = {l, r, i};
    }
    sort(qu+1, qu+1+Q);
    int cnt = 0;
    for(int i = 1; i<=Q; i++){
        query q = qu[i];
        while(r < q.r){
            ++r;
            if(arr[r] <= N){
                fre[arr[r]]++;
                if(fre[arr[r]] == arr[r]){
                    cnt++;
                }
                if(fre[arr[r]] == arr[r]+1){
                    cnt--;
                }
            }
        }
        while(l < q.l){
            if(arr[l] <= N){
                fre[arr[l]]--;
                if(fre[arr[l]] == arr[l]){
                    cnt++;
                }
                if(fre[arr[l]] == arr[l]-1){
                    cnt--;
                }
            }
            l++;
        }
        while(r > q.r){
            if(arr[r] <= N){
                fre[arr[r]]--;
                if(fre[arr[r]] == arr[r]){
                    cnt++;
                }
                if(fre[arr[r]] == arr[r]-1){
                    cnt--;
                }
            }
            r--;
        }
        while(l > q.l){
            l--;
            if(arr[l] <= N){
                fre[arr[l]]++;
                if(fre[arr[l]] == arr[l]){
                    cnt++;
                }
                if(fre[arr[l]] == arr[l]+1){
                    cnt--;
                }
            }
        }
        ans[q.id] = cnt;
    }
    for(int  i= 1; i<=Q; i++){
        printf("%d\n", ans[i]);
    }
}