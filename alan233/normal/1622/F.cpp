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

const int N=1000005;

vector<int>inz[N];
int n;

void xxs(int n){
    static bool vis[N];
    static int pr[N],len;
    rep(i,2,n){
        if(!vis[i])pr[++len]=i;
        for(int j=1;j<=len&&pr[j]*i<=n;j++){
            vis[pr[j]*i]=1;
            if(i%pr[j]==0)break;
        }
    }    
    static int num[N];
    rep(i,1,n){
        num[i]=i;
    }
    rep(i,1,len){
        for(int j=pr[i];j<=n;j+=pr[i]){
            int dlt=0;
            while(num[j]%pr[i]==0)num[j]/=pr[i],dlt^=1;
            if(dlt)inz[j].pb(pr[i]);
        }
    }
}

int kel[N],wa;
void fuck(int pos){
    if(kel[pos]==0)wa++,kel[pos]=1;
    else wa--,kel[pos]=0;
}

void check1(){
    rep(i,1,n){
        for(auto it:inz[i])fuck(it);
        if(!wa){
            printf("%d\n",n-1);
            rep(j,1,n){
                if(j!=i)printf("%d ",j);
            }
            puts("");
            exit(0);
        }
    } 
    rep(i,1,n){
        for(auto it:inz[i])fuck(it);
    }
}

void check2(){
    rep(ban,max(1,n/2-3),min(n,n/2+3)){
        rep(i,1,ban)for(auto it:inz[i])fuck(it);
        rep(i,1,n){
            for(auto it:inz[i])fuck(it);
            if(!wa){
//                printf("i=%d,ban=%d\n",i,ban);
                printf("%d\n",n-2);
                rep(j,1,n){
                    if(j!=i&&j!=ban)printf("%d ",j); 
                } 
                puts("");
                exit(0);
            }
        }
        rep(i,1,n)for(auto it:inz[i])fuck(it);
        rep(i,1,ban)for(auto it:inz[i])fuck(it);
    }    
}

int main(){
    n=read();
//    n=1e6;
    xxs(n);
//    cerr<<clock()<<'\n';
    
    if(n==1){
        puts("1");
        puts("1");
        return 0;
    } 
    if(n==3){
        puts("1");
        puts("1");
        return 0;
    }
/*
    rep(i,1,n){
        printf("inz[%d]=",i);
        for(auto it:inz[i])printf("%d ",it);puts("");
    }
*/
    rep(i,1,n){
        if((n-i+1)&1){
            for(auto it:inz[i]){
                fuck(it);
            }
        }
    }
    // check ans=n-1
    check1();
    // check ans=n-2
    check2();
    // check ans=n-3
    assert(n%2==1);
    rep(i,1,n){
        for(auto it:inz[i])fuck(it);
    }
    n--;
    check2();
}