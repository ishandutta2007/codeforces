#include <bits/stdc++.h>
using namespace std;

void solve(){
    int k, n, m;
    scanf("%d %d %d", &k, &n, &m);
    vector<int> A(n);
    for(int i = 0; i < n; i++) scanf("%d", &A[i]);
    vector<int> B(m);
    for(int i = 0; i < m; i++) scanf("%d", &B[i]);
    int ap = 0;
    int bp = 0;
    vector<int> ans;
    while(ap < n || bp < m){
        if(ap < n && A[ap] <= k){
            ans.push_back(A[ap]);
            if(A[ap] == 0) k++;
            ap++;
        }
        else if(bp < m && B[bp] <= k){
            ans.push_back(B[bp]);
            if(B[bp] == 0) k++;
            bp++;
        }
        else{
            printf("-1\n");
            return;
        }
    }
    for(int i = 0; i < n + m; i++){
        printf("%d", ans[i]);
        if(i == n + m - 1) printf("\n");
        else printf(" ");
    }
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    
}