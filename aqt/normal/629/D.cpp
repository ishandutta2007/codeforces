#include <bits/stdc++.h>

using namespace std;

int N;
long long BIT[100005];
long long R[100005], h[100005];
vector<long long> vec;

void upd(int p, long long v){
    for(int i = p; i<=N; i+=i&-i){
        BIT[i] = max(BIT[i], v);
    }
}

long long qu(int p){
    long long ans = 0;
    for(int i = p; i>0; i-=i&-i){
        ans = max(BIT[i], ans);
    }
    return ans;
}

int main(){
    scanf("%d", &N);
    for(int i = 1; i<=N; i++){
        scanf("%d %d", &R[i], &h[i]);
        vec.push_back(R[i]*R[i]*h[i]);
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    long long ans = 0;
    for(int i = 1; i<=N; i++){
        int l = 1, r = vec.size(), idx = 0;
        long long crnt = R[i]*R[i]*h[i];
        while(l <= r){
            int mid = (l+r)>>1;
            if(vec[mid-1] <= crnt){
                idx = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        long long v = qu(idx-1);
        v += crnt;
        upd(idx, v);
        ans = max(ans, v);
    }
    printf("%.14f", ans*3.14159265359);
}