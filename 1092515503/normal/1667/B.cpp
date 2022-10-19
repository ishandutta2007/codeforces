/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETEMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,m;
ll a[500100],b[500100];
int p[500100],s[500100],o[500100],f[500100];
void PA(int x,int y){while(x<=m)p[x]=max(p[x],y),x+=x&-x;}
int PQ(int x){int y=0xc0c0c0c0;while(x)y=max(y,p[x]),x-=x&-x;return y;}
void SA(int x,int y){while(x)s[x]=max(s[x],y),x-=x&-x;}
int SQ(int x){int y=0xc0c0c0c0;while(x<=m)y=max(y,s[x]),x+=x&-x;return y;}
void mina(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]),a[i]+=a[i-1];
    for(int i=0;i<=n;i++)b[i]=a[i];
    sort(b,b+n+1),m=unique(b,b+n+1)-b;
    for(int i=1;i<=m;i++)p[i]=s[i]=o[i]=0xc0c0c0c0;
    for(int i=0;i<=n;i++)a[i]=lower_bound(b,b+m,a[i])-b+1;
    // for(int i=0;i<=n;i++)printf("%d ",a[i]);puts("");
    o[a[0]]=max(o[a[0]],0),SA(a[0],0),PA(a[0],0);
    for(int i=1;i<=n;i++){
        f[i]=max({o[a[i]],PQ(a[i]-1)+i,SQ(a[i]+1)-i});
        // printf("%d\n",f[i]);
        o[a[i]]=max(o[a[i]],f[i]);
        SA(a[i],f[i]+i);
        PA(a[i],f[i]-i);
    }
    printf("%d\n",f[n]);
}
int main(){
    scanf("%d",&T);
    while(T--)mina();
    return 0;
}