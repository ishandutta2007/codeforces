#include<iostream>
#include <memory.h>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define clr(a,v) memset(a,v,sizeof(a))
typedef long long lng;
const int INF=1000000000;
const lng LINF=1LL*INF*INF;

int n,m;
int A[25];
lng res;
const int D=25;
const int D2=D+25;

struct mat{
    lng a[D][D];
    void iden(){
        forn(i,D){
            forn(j,D){
                a[i][j]=LINF;
            }
            a[i][i]=0;
        }
    }
    void mul(const mat&x,const mat&y){
        forn(i,D){
            forn(j,D){
                a[i][j]=LINF;
                forn(k,D){
                    a[i][j]=min(a[i][j],x.a[i][k]+y.a[k][j]);
                }
            }
        }
    }
};

mat m1;
lng dp[25][D2];

void docost(int d0){
    forn(i,n+1){
        forn(d,D2){
            dp[i][d]=LINF;
        }
    }
    dp[0][d0]=0;
    forn(i,n){
        forn(d,D2){
            if(d+1<D2)
                dp[i+1][d+1]=min(dp[i+1][d+1],dp[i][d]);
            if(d-1>=0)
                dp[i+1][d-1]=min(dp[i+1][d-1],dp[i][d]+A[i]);
        }
    }
    forn(d,D){
        m1.a[d0][d]=dp[n][d];
    }
}

int main()
{
    //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

    cin>>n>>m;
    forn(i,n){
        cin>>A[i];
        res+=A[i]*m;
    }
    forn(i,n){
        int t;
        cin>>t;
        A[i]=t-A[i];
    }
    forn(i,D){
        docost(i);
    }
    mat r,a=m1;
    r.iden();
    while(m){
        if(m&1){
            m1=r;
            r.mul(m1,a);
        }
        m>>=1;
        m1=a;
        a.mul(m1,m1);
    }
    cout<<res+r.a[0][0];

    return 0;
}