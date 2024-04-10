#include<stdio.h>
#include<algorithm>
using namespace std;
__int64 n,w[100002][3],m,s[100002],t=-1,v[100002],c,top,stack[100002],r[100002],t1,z[100001],l[100001];
struct A{
    __int64 a,b;
    bool operator()(A p,A q){
        if(p.a<q.a)return 1;
        return 0;}
}D[200002];
__int64 ssss,ss,ss2,sss;
void DFS(){
    while(top>0){
        t1=top;
        while(r[top-1]!=l[stack[top-1]]){
            if(v[D[r[top-1]].b]==1){
                r[top-1]++;
                continue;}
            v[D[r[top-1]].b]=1;
            stack[top]=D[r[top-1]].b;r[top]=s[stack[top]];
            r[top-1]++;
            c++;
            top++;
            break;}
        if(t1==top){
            stack[top-1]=0;
            r[top-1]=0;
            top--;}
    }
}
int main(){
    int i;
    scanf("%I64d",&n);
    for(i=1;i<n;i++){
        scanf("%I64d%I64d%I64d",&w[i][0],&w[i][1],&w[i][2]);
        while(w[i][2]>0){
            if(w[i][2]%10!=4&&w[i][2]%10!=7)break;
            w[i][2]/=10;}
        if(w[i][2]!=0){
            D[m].a=w[i][0],D[m++].b=w[i][1];
            D[m].b=w[i][0],D[m++].a=w[i][1];}
    }
    sss=n;
    sss*=(n-1);
    sss*=(n-2);
    if(m==0){
        printf("%I64d\n",sss);
        return 0;
    }
    stable_sort(D,D+m,A());
    s[D[0].a]=0;
    t=D[0].a;
    for(i=0;i<m;i++){
        if(t!=D[i].a){
            l[t]=i;
            s[D[i].a]=i;
            t=D[i].a;}}
    l[D[m-1].a]=m;
    for(i=0;i<m;i++)z[D[i].a]=1,z[D[i].b]=1;
    for(i=1;i<=n;i++){
        c=0;
        if(v[i]==0&&z[i]==1){c=1;v[i]=1;r[top]=s[i];stack[top++]=i;DFS();top=0;}
        ss=c;
        ss*=(c-1)*2;
        ss*=(n-c);
        ss2=c;
        ss2*=(c-1);
        ss2*=(c-2);
        ssss+=ss;
        ssss+=ss2;}
    printf("%I64d\n",sss-ssss);
}