#include <bits/stdc++.h>
#define ll long long    
using namespace std;
ll c,sc,n,m,i,j,a,b,z[10000],d[10000],z1[10000],d1[10000],a1,b1,c1,k;
int main() {
    cin >> n >> k;
    for(i=0;i<n;i++)
    {
        cin >> a >> b;
        d[a]+=b;
    }
  
    ll sc=0;
    for(i=1;i<=3001;i++)
    {
        ll v=k;
       	if(d[i-1]<v){v-=d[i-1]; sc+=d[i-1]; d[i-1]=0;}
        if(d[i-1]>=v){sc+=v; d[i-1]-=v; v=0;}
  	if(d[i]<v){v-=d[i]; sc+=d[i]; d[i]=0;}
  	if(d[i]>=v){d[i]-=v; sc+=v; v=0; }	        
     }
    
    cout << sc << endl;
    return 0;
}