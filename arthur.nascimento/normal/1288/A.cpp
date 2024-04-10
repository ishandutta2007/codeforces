#include <bits/stdc++.h>
#define maxn 400400
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define debug printf
#define mk make_pair
#define pii pair<int,int>
#define mod 1000000007 
using namespace std;
 
main(){
    int nt;
    scanf("%d",&nt);
    while(nt--){
        int n,d;
        scanf("%d%d",&n,&d);
        int t = sqrt(d);
        int ans = 0;
        for(int i=max(0,t-100);i<=t+100;i++)
            if(i + d/(i+1) +   (d%(i+1) > 0) <= n) ans = 1;
        if(ans) printf("YES\n");
        else printf("NO\n");
        
    }
}