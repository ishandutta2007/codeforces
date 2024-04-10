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
        
        int n,d;
        scanf("%d%d",&n,&d);
        for(int i=0;i<n;i++)
            scanf("%d",v+i);
        for(int i=1;i<n;i++){
            
            while(d >= i && v[i] >= 1){
                v[i]--;
                v[0]++;
                d -= i;
            }
            
        }
        
        printf("%d\n",v[0]);
        
    }
}