#include <bits/stdc++.h>
#define maxn 2002000
using namespace std;

int pr[maxn];
int v[maxn];

int main() {
    for(int i=2;i<maxn;i++){
        pr[i] = 1;
        for(int j=2;j*j<=i;j++)
            if(i%j == 0){
                pr[i] = 0;
                break;
            }
    }
    int n, q1 = 0, add = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",v+i);
        q1 += (v[i] == 1);
        if(v[i] != 1) add |= pr[v[i]+1];
    }
    int ans = max(1,q1+add);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(pr[v[i]+v[j]])
                ans = max(ans,2);
   printf("%d\n",ans);
   if(ans > 2){
       for(int i=0;i<n;i++){
           if(v[i] == 1)
            printf("1 ");
           else if(pr[v[i]+1] && add){
               add = 0;
               printf("%d ",v[i]);
           }
       }
   }
   else if(ans == 1)
    printf("%d ",v[0]);
   else
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(pr[v[i]+v[j]]){
                printf("%d %d\n",v[i],v[j]);
                return 0;
            }
}