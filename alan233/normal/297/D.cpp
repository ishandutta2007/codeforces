#pragma GCC optimize(2,3,"Ofast")
#pragma GCC target("avx","avx2")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) (int(x.size()))
#define pii pair<int,int>
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<class T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<class T>void print(T x,char let){print(x),putchar(let);}
template<class T1,class T2>void ckmin(T1&x,T2 y){if(x>y)x=y;}
template<class T1,class T2>void ckmax(T1&x,T2 y){if(x<y)x=y;}

const int N=1005;

char row[N][N],col[N][N];
int n,m,k;
int a[N][N];

int main(){
    scanf("%d%d",&n,&m);
    scanf("%d",&k);
    rep(_,1,2*n-1){
        if(_&1){
            int i=_/2+1;
            scanf("%s",row[i]+1);
        }else{
            int i=_/2;
            scanf("%s",col[i]+1);
        }
    }
    
    if(k==1){
        int qwq=0;
        rep(i,1,n)rep(j,1,m-1)if(row[i][j]=='E')qwq++;
        rep(j,1,m)rep(i,1,n-1)if(col[i][j]=='E')qwq++;
        if(qwq*4>=(n*(m-1)+m*(n-1))*3){
            puts("YES");
            rep(i,1,n){
                rep(j,1,m)
                    printf("1 ");
                puts("");
            }
        }else{
            puts("NO");
        }
        return 0;
    }
    
    if(n<=m){
        rep(i,1,n){
            int dif=0;
            a[i][1]=0;
            dif+=(col[i-1][1]=='E')^(a[i][1]==a[i-1][1]);
            rep(j,2,m){
                a[i][j]=row[i][j-1]=='E'?a[i][j-1]:a[i][j-1]^1;
                dif+=(col[i-1][j]=='E')^(a[i][j]==a[i-1][j]);
            }
            if(i>1&&dif>m/2){
                rep(j,1,m)a[i][j]^=1;
            }
        }
    }else{
        rep(j,1,m){
            int dif=0;
            a[1][j]=0;
            dif+=(row[1][j-1]=='E')^(a[1][j]==a[1][j-1]);
            rep(i,2,n){
                a[i][j]=col[i-1][j]=='E'?a[i-1][j]:a[i-1][j]^1;
                dif+=(row[i][j-1]=='E')^(a[i][j]==a[i][j-1]);
            }
            if(j>1&&dif>n/2){
                rep(i,1,n)a[i][j]^=1;
            }
        }
    }
    puts("YES");
    rep(i,1,n){
        rep(j,1,m){
            printf("%d ",a[i][j]+1);
        }
        puts("");
    }
    return 0;
}