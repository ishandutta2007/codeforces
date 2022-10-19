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
int n,q,ch[150010][2],fa[150010],jum[150010],muj[150010],dep[150010];
struct node{
    int a[27];bool ok;
    node(){memset(a,0,sizeof(a)),ok=true;}
    friend node operator+(const node&u,const node&v){
        node w;
        for(int i=0;i<=26;i++)w.a[i]=u.a[i]+v.a[i];
        w.ok=u.ok&v.ok;
        return w;
    }
    friend node operator&(const node&u,const node&v){
        // u.print(),v.print();
        node w;int U=u.a[26],V=v.a[26];
        for(int i=0;i<26;i++){
            w.a[i]=max(u.a[i],v.a[i]);
            U-=w.a[i]-u.a[i];
            V-=w.a[i]-v.a[i];
        }
        assert(U==V);w.a[26]=U;
        w.ok=(u.ok&&v.ok&&U>=0);
        return w;
    }
    void print()const{for(int i=0;i<=26;i++)printf("%d ",a[i]);puts("");}
    int operator()()const{
        if(!ok)return -1;
        int ret=0;
        for(int i=0;i<26;i++)ret+=(a[i]+a[26])*(i+1);
        return ret;
    }
}f[150010],b[150010];
char s[150010];
int HS(char c){return c=='?'?26:c-'a';}
void rebuild(int i){
    if(i)f[i]=(f[muj[ch[i][0]]]+b[muj[ch[i][0]]])&(f[muj[ch[i][1]]]+b[muj[ch[i][1]]]),rebuild(jum[i]);
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++){
        scanf("%d%s",&fa[i],s+i),dep[i]=dep[fa[i]]+1;
        ch[fa[i]][ch[fa[i]][0]?1:0]=i;
    }
    int ped=-1;
    for(int i=1;i<=n;i++)if(!ch[i][0]){
        if(ped==-1)ped=dep[i];
        if(ped!=dep[i]){for(int j=0;j<q;j++)puts("Fou");return 0;}
    }
    for(int i=2;i<=n;i++)if(!ch[fa[i]][1])jum[i]=jum[fa[i]];else jum[i]=fa[i];
    for(int i=1;i<=n;i++)if(!ch[i][0]||ch[i][1])muj[i]=i;
    for(int i=n;i>=2;i--)if(!muj[fa[i]])muj[fa[i]]=muj[i];
    for(int i=2;i<=n;i++)b[muj[i]].a[HS(s[i])]++;
    for(int i=n;i;i--)if(ch[i][1])
        f[i]=(f[muj[ch[i][0]]]+b[muj[ch[i][0]]])&(f[muj[ch[i][1]]]+b[muj[ch[i][1]]]);
    // for(int i=2;i<=n;i++)printf("%d %d\n",jum[i],muj[i]);
    // f[1].print();
    for(int i=1,x;i<=q;i++){
        static char t[10];
        scanf("%d%s",&x,t);
        b[muj[x]].a[HS(s[x])]--,s[x]=t[0],b[muj[x]].a[HS(s[x])]++;
        rebuild(jum[x]);
        node F=f[muj[1]]+b[muj[1]];
        if(!F.ok)puts("Fou");else printf("Shi %d\n",F());
    }
    return 0;
}