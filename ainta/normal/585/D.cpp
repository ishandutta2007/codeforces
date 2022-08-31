#include<cstdio>
#include<algorithm>
using namespace std;
int n, cnt;
long long po[30];
struct point{
    int A, B, C, mask;
    bool operator <(const point &p)const{
        return A!=p.A?A<p.A:B!=p.B?B<p.B:C<p.C;
    }
}w[25],U[2010000];
void Do1(int pv, int ed, int A, int B, int C, int mask){
    if(pv==ed){
        U[cnt++]={B-A,C-A,-A,mask};
        return;
    }
    Do1(pv+1,ed,A+w[pv].A,B+w[pv].B,C,mask*3);
    Do1(pv+1,ed,A+w[pv].A,B,C+w[pv].C,mask*3+1);
    Do1(pv+1,ed,A,B+w[pv].B,C+w[pv].C,mask*3+2);
}
int Mx = -1e9;
long long pp;
void Do2(int pv, int ed, int A, int B, int C, int mask){
    if(pv==ed){
        point tp = {A-B,A-C,-999999999,mask};
        int pv = lower_bound(U,U+cnt,tp)-U;
        if(pv==cnt || U[pv].A!=tp.A || U[pv].B!=tp.B)return;
        int s = -U[pv].C+A;
        if(Mx < s){
            Mx = s;
            pp = po[n-(n/2+1)]*U[pv].mask + mask;
        }
        return;
    }
    Do2(pv+1,ed,A+w[pv].A,B+w[pv].B,C,mask*3);
    Do2(pv+1,ed,A+w[pv].A,B,C+w[pv].C,mask*3+1);
    Do2(pv+1,ed,A,B+w[pv].B,C+w[pv].C,mask*3+2);
}
int CK[50];
int main(){
    int i;
    scanf("%d",&n);
    po[0]=1;
    for(i=0;i<25;i++)po[i+1]=po[i]*3;
    for(i=0;i<n;i++){
        scanf("%d%d%d",&w[i].A,&w[i].B,&w[i].C);
    }
    int M=n/2+1;
    Do1(0,M,0,0,0,0);
    sort(U,U+cnt);
    Do2(M,n,0,0,0,0);
    if(Mx<-8e8){
        puts("Impossible");
        return 0;
    }
    //printf("%d\n",Mx);
    for(i=n-1;i>=0;i--){
        CK[i]=pp%3;
        pp/=3;
    }
    for(i=0;i<n;i++){
        if(CK[i]==0)printf("LM");
        else if(CK[i]==1)printf("LW");
        else printf("MW");
        puts("");
    }
}