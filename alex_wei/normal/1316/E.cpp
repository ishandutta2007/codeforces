#include <bits/stdc++.h>
using namespace std;

//&Start
#define inf 0x3f3f3f3f
#define re register
#define il inline
#define hash unorded_map
typedef long long lng;
typedef unsigned long long ulng;
typedef vector<int> veci;

//&Data
#define N 100000
#define P 128
int a[N+5],s[N+5][8],one[P+5];
veci ord;
lng g[P+5],f[P+5];

//&Main
il bool cmp(re int x,re int y){return a[x]>a[y];}
int main(){
    re int n,p,k;
    scanf("%d%d%d",&n,&p,&k);
    re int ful=(1<<p)-1;
    for(re int i=1;i<=ful;i++) one[i]=one[i-(i&-i)]+1;
    for(re int i=1;i<=n;i++) scanf("%d",a+i);
    for(re int i=1;i<=n;i++) ord.push_back(i);
    sort(ord.begin(),ord.end(),cmp);
    for(re int i=1;i<=n;i++)
        for(re int j=1;j<=p;j++) scanf("%d",s[i]+j);
    fill(f+1,f+ful+1,-1),f[0]=0;
    re int yest=-1;
    for(re int i:ord){
        swap(f,g),fill(f+1,f+ful+1,-1),yest++;
        for(re int j=0;j<=ful;j++){
            if(~g[j]) f[j]=(yest-one[j]<k?g[j]+a[i]:g[j]);
            for(re int t=1;t<=p;t++)
                if((j&(1<<(t-1)))&&~g[j^(1<<(t-1))])
                    f[j]=max(f[j],g[j^(1<<(t-1))]+s[i][t]);
        }
    }
    printf("%lld\n",f[ful]);
    return 0;
}