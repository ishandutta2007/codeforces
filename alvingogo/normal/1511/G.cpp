#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
    int n,m;
    cin >> n >> m;
    vector<int> c(m+1),p(m+1);
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        a--;
        c[a]^=1;
    }
    p[0]=c[0];
    for(int i=1;i<m;i++){
        p[i]=p[i-1]^c[i];
    }
    const int b=20;
    vector<vector<int> > f(m,vector<int>(b));
    for(int j=1;j<b;j++){
        for(int i=0;i<m;i++){
            if(i+(1<<j)<=m){
                f[i][j]=f[i][j-1]^f[i+(1<<(j-1))][j-1]^((1<<(j-1))*(p[(i+(1<<j)-1)]^p[(i+(1<<(j-1)))-1]));
            }
        }
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        int g=0;
        for(int j=b-1;j>=0;j--){
            if(l+(1<<j)<=r){
                g^=f[l][j];
                if(p[r]^p[(l+(1<<j))-1]){
                    g^=(1<<j);
                } 
                l+=(1<<j);
            }
        }
        cout << (g?'A':'B');
    }
    cout << "\n";
    return 0;
}