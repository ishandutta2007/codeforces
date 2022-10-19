#include <bits/stdc++.h>
#define maxn 4004000
#define pb push_back
#define debug 
typedef long long ll;
using namespace std;

int ans[maxn];

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int x = 0, s = 0;
    while(s + x + 1 <= a + b){
        x++;
        ans[x] = 1;
        s += x;
    }
    int p = x, q = 0;
    while(b >= x && x > 0){
        ans[x] = 2;
        b -= x;
        x--;
        p--;
        q++;
    }
    if(b && ans[b] == 1){
        ans[b] = 2;
        p--;
        q++;
    }
    
    printf("%d\n",p);
    for(int i=1;i<=p+q;i++)
        if(ans[i] == 1)
            printf("%d ",i);
    printf("\n");
    printf("%d\n",q);
    for(int i=1;i<=p+q;i++)
        if(ans[i] == 2)
            printf("%d ",i);
    printf("\n");
    
}