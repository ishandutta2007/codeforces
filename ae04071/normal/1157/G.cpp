#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n,m,arr[200][200];

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&arr[i][j]);
    if(n==1) {
        puts("YES");
        printf("0\n");
        for(int j=0;j<m;j++) {
            if(arr[0][j]==0) printf("0");
            else printf("1");
        }
        return 0;
    }

    for(int k=0;k<n;k++) {
        vector<int> a,b;
        int f=1;
        for(int i=0;i<n;i++) if(i!=k) {
            vector<int> ta,tb;
            for(int j=0;j<m;j++) if(arr[i][j]==0) ta.push_back(j); else tb.push_back(j);
            if(ta>tb) swap(ta,tb);
            if(b.empty()) a=ta,b=tb;
            else if(a!=ta) {
                f=0;
                break;
            }
        }
        if(f) {
            vector<int> tmp(arr[k],arr[k]+m);
            for(int i=0,j=0;i<m;i++) {
                if(j<a.size() && i==a[j]) tmp[i]^=1,j++;
            }
            if(tmp[0]==1) for(int j=0;j<m;j++) tmp[j]^=1;
            
            int j=0;
            for(;j<m && tmp[j]==0;j++);
            for(;j<m && tmp[j]==1;j++);
            if(j==m) {
                puts("YES");
                for(int i=0;i<n;i++) {
                    for(int j=0,k=0;j<m;j++) if(k<a.size() && j==a[k]) arr[i][j]^=1,k++;
                    if((i<=k && arr[i][0]==1) || (i>k && arr[i][0]==0)) printf("1");
                    else printf("0");
                }
                puts("");
                for(int i=0,j=0;i<m;i++) {
                    if(j<a.size() && i==a[j]) printf("1"),j++;
                    else printf("0");
                }
                return 0;
            }
        }
    }
    puts("NO");
    
    return 0;
}