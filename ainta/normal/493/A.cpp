#include<stdio.h>
#include<algorithm>
using namespace std;
struct A{
    int t, ck, num, c;
    bool operator<(const A &p)const{
        return t<p.t;
    }
}w[100];
int n, C[200];
char p[1010], q[1010];
int main(){
    int i;
    scanf("%s%s",p,q);
    scanf("%d",&n);
    char pp[3], qq[3];
    for(i=1;i<=n;i++){
        scanf("%d%s%d%s",&w[i].t,pp,&w[i].num,qq);
        if(pp[0]=='h')w[i].ck = 0;
        else w[i].ck = 1;
        if(qq[0]=='y')w[i].c=1;
        else w[i].c=2;
    }
    sort(w+1,w+n+1);
    for(i=1;i<=n;i++){
        if(C[w[i].num+w[i].ck*100]>=2)continue;
        C[w[i].num+w[i].ck*100]+=w[i].c;
        if(C[w[i].num+w[i].ck*100]>=2)printf("%s %d %d\n",w[i].ck?q:p, w[i].num, w[i].t);
    }
}