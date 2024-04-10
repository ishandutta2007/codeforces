#include <bits/stdc++.h>
#define maxn 400400
#define pii pair<int,int>
#define pb push_back
#define inf 1e9
#define mod 998244353
#define fill rtgrtg
#define debug 
typedef long long ll;
using namespace std;

int n,t;

int find(int pref){
    
    if(pref == n)
        return t;
        
    int expect = n-t;
    int u;
    
    while(1){
        
        printf("? %d %d\n",pref+1,n);fflush(stdout);
        scanf("%d",&u);
        printf("? %d %d\n",pref+1,n);fflush(stdout);
        scanf("%*d");
        if(u != expect)
            break;
    }
    
    int len = n-pref;
    int ret = (t+u-len)/2;
    
    while(1){
        printf("? %d %d\n",pref+1,n);fflush(stdout);
        scanf("%d",&u);
        printf("? %d %d\n",pref+1,n);fflush(stdout);
        scanf("%d",&u);
        if(u == t)
            break;
    }
    
    return ret;
    
}

int si[330];
int ans[330];

int main(){
  
    scanf("%d%d",&n,&t);
    
    for(int i=1;i<=n;i++)
        if(i%2 == 1)
            si[i] = find(i);
     
     for(int i=1;i<=n;i++)
        debug("si %d = %d\n",i,si[i]);
            
    int ones_left = 0, ones_right = t;
            
    ans[1] = si[1];
    ones_left += ans[1];
    ones_right -= ans[1];
  
    for(int i=3;i<=n;i+=2){
        
        int cur = si[i]-si[i-2];
        ones_right -= cur;
        
        if(cur == 0){
            ans[i-1] = ans[i] = 0;
            continue;
        }
        if(cur == 2){
            ans[i-1] = ans[i] = 1;
            ones_left += 2;
            continue;
        }
        
        
        int expect = n-t;
        int u;
        
        for(int y=0;y<23;y++){
            
            printf("? %d %d\n",i,n); fflush(stdout);
            scanf("%d",&u);
            printf("? %d %d\n",i,n); fflush(stdout);
            scanf("%*d");
            if(u != expect)
                break;
            
        }
        
        int zeroR = n-i-ones_right;
        int k = (u-ones_left-zeroR)/2;
        debug("%d - %d - %d\n",u,ones_left,zeroR);
        
        if(k == 1)
            ans[i-1] = 1, ans[i] = 0;
        else
            ans[i-1] = 0, ans[i] = 1;
        
        while(1){
        printf("? %d %d\n",i,n);fflush(stdout);
        scanf("%d",&u);
        printf("? %d %d\n",i,n);fflush(stdout);
        scanf("%d",&u);
        if(u == t)
            break;
        }
        
        ones_left++;
    }
    
    
    
    if(n%2 == 0){
        int st = 0;
        for(int i=1;i<n;i++) st += ans[i];
        ans[n] = t-st;
    }
    
    printf("! ");
    for(int i=1;i<=n;i++)
        printf("%d",ans[i]);
    printf("\n");fflush(stdout);
 
}