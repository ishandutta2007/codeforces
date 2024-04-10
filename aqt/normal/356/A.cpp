#include <bits/stdc++.h>

using namespace std;

set<int> s;
int N, M;
int ans[300005];

int main(){
    cin >> N >> M;
    for(int i= 1; i<=N; i++){
        s.insert(i);
    }
    s.insert(N+1);
    for(int i =1 ; i<=M; i++){
        int l, r, x;
        cin >> l >> r >> x;
        while(*s.lower_bound(l) <= r){
            int k = *s.lower_bound(l);
            ans[k] = x;
            s.erase(k);
        }
        ans[x] = 0;
        s.insert(x);
    }
    for(int i= 1; i<=N; i++){
        printf("%d ", ans[i]);
    }
}