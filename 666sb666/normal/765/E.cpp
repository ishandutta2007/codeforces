#include <cstdio>
#include <cstdlib>
int a[200105],b[200105<<1],c[200105<<1];
int tot,t2=-1,n;
inline void read(int &x){
    x=0;int f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
    x*=f;
}
inline void asd(int x);
inline int check(int x,int fa){
    int t1=-1;
    for (int i=a[x];i;i=b[i]) if (c[i]!=fa){
        int ttt=c[i];
        int y=check(ttt,x);
        if (t1==-1) t1=y;
        else if (t1!=y) {
            if (fa!=0){
                asd(-1);
            }else {
                if (t2==-1) t2=y;
                else if (t2!=y){
                    asd(-1);
                }
            }
        }
    }
    if (!fa){
        int ans=t1+t2+2;
        while ((ans>0) && (!(ans&1))) ans/=2;
        asd(ans);
    }
    return t1+1;
}
inline void asd(int x){
    printf("%d\n",x);
    exit(0);
}
inline int dfs(int x,int fa){
    int t1=-1;
    for (int i=a[x];i;i=b[i]){
        int ttt=c[i];
        if (fa!=ttt){
            int y=dfs(ttt,x);
            if (t1==-1) t1=y;
            else if (t1!=y)check(x,0);
        }
    }
    if (!fa)check(x,0);
    return t1+1;
}
int ans;
int main(){
    read(n);
    int x,y;
    for (int i=1;i<n;i++){
        read(x);
        read(y);
        b[++tot]=a[x];a[x]=tot;c[tot]=y;
        b[++tot]=a[y];a[y]=tot;c[tot]=x;
    }
    ans=dfs(1,0);
    printf("%d\n",(ans&1)?(ans/2):0);
}