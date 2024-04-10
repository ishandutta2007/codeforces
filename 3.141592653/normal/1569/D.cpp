// qaq?
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#pragma GCC optimize(3)

#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>

#define int long long
const int MN=1e6+5;
const int N=1e6;

using namespace std;

inline int read(){
    int x=0,f=1;char c=getchar();
    for(;(c<'0'||c>'9');c=getchar()){if(c=='-')f=-1;}
    for(;(c>='0'&&c<='9');c=getchar())x=x*10+(c&15);
    return x*f;
}

int t,n,m,k;
int sx[MN],sy[MN],x[MN],y[MN];
int px[MN],py[MN],visx[MN],visy[MN];

struct Node{int vx,vy;}valx[MN],valy[MN];

bool c1(Node p,Node q){return (p.vx==q.vx)?(p.vy<q.vy):(p.vx<q.vx);}
bool c2(Node p,Node q){return (p.vy==q.vy)?(p.vx<q.vx):(p.vy<q.vy);}

signed main(void){

    t=read();
    while(t--){
        n=read(),m=read(),k=read();int num1=0,num2=0;
        for(int i=1;i<=n;i++)x[i]=read(),visx[x[i]]=1;
        for(int i=1;i<=m;i++)y[i]=read(),visy[y[i]]=1;
        for(int i=1;i<=k;i++){
            px[i]=read(),py[i]=read();
            if(visx[px[i]]&&visy[py[i]])continue;
            if(visx[px[i]])num1++,valx[num1].vx=px[i],valx[num1].vy=py[i];
            if(visy[py[i]])num2++,valy[num2].vx=px[i],valy[num2].vy=py[i];
        }

        int pi=1,cnt=0,res=0,ans=0;bool f=0;
        sort(valx+1,valx+num1+1,c1);
        for(int i=1;i<=num1;i++){
            // cout<<valx[i].vx<<" "<<valx[i].vy<<" "<<cnt<<" "<<pi<<" "<<y[pi]<<" "<<sy[pi]<<endl;
            if(valx[i].vx!=valx[i-1].vx){f=1;sy[pi]+=cnt;res+=cnt*(cnt-1)/2;pi=upper_bound(y+1,y+m+1,valx[i].vy)-y;cnt=1;continue;}
            if(valx[i].vy>y[pi]){f=1;sy[pi]+=cnt;res+=cnt*(cnt-1)/2;pi=upper_bound(y+1,y+m+1,valx[i].vy)-y,cnt=1;continue;}
            if(valx[i].vy<y[pi])cnt++,f=0;
        }
        sy[pi]+=cnt,res+=cnt*(cnt-1)/2;
        // puts("");

        sort(valy+1,valy+num2+1,c2);cnt=0;pi=1,f=0;
        for(int i=1;i<=num2;i++){
            // cout<<valy[i].vx<<" "<<valy[i].vy<<" "<<cnt<<" "<<pi<<" "<<x[pi]<<" "<<sx[pi]<<endl;
            if(valy[i].vy!=valy[i-1].vy){f=1;sx[pi]+=cnt;res+=cnt*(cnt-1)/2;pi=upper_bound(x+1,x+n+1,valy[i].vx)-x;cnt=1;continue;}
            if(valy[i].vx>x[pi]){f=1;sx[pi]+=cnt;res+=cnt*(cnt-1)/2;pi=upper_bound(x+1,x+n+1,valy[i].vx)-x,cnt=1;continue;}
            if(valy[i].vx<x[pi])f=0,cnt++;
        }
        sx[pi]+=cnt;res+=cnt*(cnt-1)/2;

        for(int i=2;i<=n;i++)ans+=sx[i]*(sx[i]-1)/2;//cout<<sx[i]<<" ";puts("");
        for(int i=2;i<=m;i++)ans+=sy[i]*(sy[i]-1)/2;//cout<<sy[i]<<" ";puts("");

        cout<<ans-res<<endl;

        for(int i=1;i<=n;i++)x[i]=visx[x[i]]=sx[i]=0;
        for(int i=1;i<=m;i++)y[i]=visy[y[i]]=sy[i]=0;
        for(int i=1;i<=k;i++)px[i]=py[i]=0;
    }

    return 0;
}