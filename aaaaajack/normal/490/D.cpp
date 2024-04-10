#include<cstdio>
#include<cstdlib>
using namespace std;
void fix(int &a,int &p2,int &p3){
    while(a%2==0){
        a/=2;
        p2++;
    }
    while(a%3==0){
        a/=3;
        p3++;
    }
}
int main(){
    int i,a1,b1,a2,b2,p[8]={0},cnt=0,tmp,x;
    scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
    fix(a1,p[0],p[1]);
    fix(b1,p[2],p[3]);
    fix(a2,p[4],p[5]);
    fix(b2,p[6],p[7]);
    if(1LL*a1*b1!=1LL*a2*b2){
        printf("-1\n");
    }
    else{
        x=4*(p[1]+p[3]<p[5]+p[7]);
        tmp=abs(p[1]+p[3]-p[5]-p[7]);
        cnt+=tmp;
        if(p[1+x]>=tmp){
            p[1+x]-=tmp;
            p[0+x]+=tmp;
        }
        else{
            p[0+x]+=p[1+x];
            tmp-=p[1+x];
            p[1+x]=0;
            p[2+x]+=tmp;
            p[3+x]-=tmp;
        }
        x=4*(p[0]+p[2]<p[4]+p[6]);
        tmp=abs(p[0]+p[2]-p[4]-p[6]);
        cnt+=tmp;
        if(p[0+x]>=tmp){
            p[0+x]-=tmp;
        }
        else{
            tmp-=p[0+x];
            p[0+x]=0;
            p[2+x]-=tmp;
        }
        for(i=0;i<p[0];i++) a1*=2;
        for(i=0;i<p[1];i++) a1*=3;
        for(i=0;i<p[2];i++) b1*=2;
        for(i=0;i<p[3];i++) b1*=3;
        for(i=0;i<p[4];i++) a2*=2;
        for(i=0;i<p[5];i++) a2*=3;
        for(i=0;i<p[6];i++) b2*=2;
        for(i=0;i<p[7];i++) b2*=3;
        printf("%d\n",cnt);
        printf("%d %d\n",a1,b1);
        printf("%d %d\n",a2,b2);
    }
    return 0;
}