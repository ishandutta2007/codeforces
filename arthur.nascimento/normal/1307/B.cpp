#include <bits/stdc++.h>
#define maxn 400400
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mod 1000000007 
#define debug printf
using namespace std;
 
int v[maxn];

int main() {
    int nt;
    scanf("%d",&nt);
    while(nt--){
        
        int n,x;
        scanf("%d%d",&n,&x);
        int has = 0, mx = 0;
        for(int i=0;i<n;i++){
            int a;
            scanf("%d",&a);
            if(a == x) has = 1;
            if(a > mx) mx = a;
        }
        
        if(has) printf("1\n");
        else {
            if(mx > x) printf("2\n");
            else {
                int ans = x/mx;
                if(x%mx) ans++;
                printf("%d\n",ans);
            }    
        
        }
        
    }
}