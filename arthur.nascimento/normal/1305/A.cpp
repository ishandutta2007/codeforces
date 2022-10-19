#include <bits/stdc++.h>
#define maxn 400400
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mod 1000000007 
#define debug(args...) printf(args)
using namespace std;

main(){
    int nt;
    scanf("%d",&nt);
    while(nt--){
        int n;
        scanf("%d",&n);
        vector<int> a,b;
        for(int i=0;i<n;i++){
            int u;
            scanf("%d",&u);
            a.pb(u);
        }
        for(int i=0;i<n;i++){
            int u;
            scanf("%d",&u);
            b.pb(u);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for(int i : a)
            printf("%d ",i);
        printf("\n");
        for(int i : b)
            printf("%d ",i);
        printf("\n");
    }
}