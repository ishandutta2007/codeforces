#include<cstdio>
#include<algorithm>
using namespace std;
int vis[210];
int T[210], TTT[210];
int len;
int Z[210][210], B[210], E[210], M[210];
int n,L;
struct point{
    int A[210];
    int E[210];
    int l;
    int num;
}st[10100];
int top;
void GetMid(int *a, int *b, int *c){
    c[L]=0;
    for(int i=0;i<L;i++)c[i]=a[i]+b[i];
    for(int i=0;i<L;i++){
        c[i+1]+=c[i]/2;
        c[i]%=2;
    }
    for(int i=0;i<L;i++)c[i]=c[i+1];
    c[L]=0;
}
int Bigger(int *a, int *b){
    for(int i=L-1;i>=0;i--){
        if(a[i]!=b[i]){
            if(a[i]<b[i])return 1;
            return 0;
        }
    }
    return 0;
}
void Add1(int *a, int *b){
    for(int i=0;i<L;i++)b[i]=a[i];
    b[0]++;
    for(int i=0;i<L;i++){
        b[i+1]+=b[i]/2;
        b[i]%=2;
    }
}
void Assign(int *a, int *b){
    for(int i=0;i<L;i++)a[i]=b[i];
}
void Print(int *a){
    for(int i=L-1;i>=0;i--)printf("%d",a[i]);
}
int Query(int a, int *b){
    printf("%d ",a);
    Print(b);
    puts("");
    fflush(stdout);
    char pp[10];
    scanf("%s",pp);
    if(pp[0]=='y')return 1;
    return 0;
}
int main(){
    int i, j;
    scanf("%d%d",&n,&L);
    for(i=1;i<=n;i++){
        for(j=0;j<L;j++)Z[i][j]=1;
    }
    for(i=0;i<L;i++)E[i]=1;
    int pv = 0, cc = 0;
    while(1){
        int bef = pv;
        while(1){
            pv++;
            if(pv>n)pv=1;
            if(!Bigger(Z[pv], B))break;
        }
        if(!Bigger(B,E)) cc++;
        else cc=0;
        if(cc>max(n,L)){
            printf("0 ");
            Print(B);
            puts("");
            fflush(stdout);
            return 0;
        }
        //Print(B);
        //printf(" ");
        //Print(E);
        //puts("");
        GetMid(B,E,M);
        for(i=0;i<L;i++)T[i]=M[i];
        if(!Query(pv, T)){
            Assign(Z[pv],T);
            top++;
            Assign(st[top].A, T);
            st[top].num = pv;
            Assign(st[top].E,E);
            Assign(E,T);
            //Print(st[top].E);
            //puts("!!!");
            continue;
        }
        Add1(T,B);
        while(top){
            Add1(st[top].A, TTT);
            if(!Bigger(B,TTT)){
                if(Bigger(E,st[top].E))Assign(E,st[top].E);
                top--;
                continue;
            }
            for(i=0;i<L;i++)T[i] = st[top].A[i];
            if(!Query(pv,T)){
                Assign(Z[pv],T);;
                Assign(E,T);
                //Print(st[top].E);
                //puts("!!!");
                break;
            }
            else{
                Add1(T,B);
                //Print(st[top].E);
                //puts("!!!");
                Assign(E, st[top].E);
                top--;
            }
        }
    }
}