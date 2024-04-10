// Author: wlzhouzhuan
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

struct node{
    int val,ii,jj;
    friend bool operator < (const node&x,const node&y){
        return x.val>y.val;
    }
}a[100005];
int n,m;
bool vis1[100005],vis2[100005];
int len;

void solve(){
    len=0;
    n=read(),m=read();
    rep(i,1,n)rep(j,1,m){
        ++len;
        a[len].val=read();
        a[len].ii=i;
        a[len].jj=j;
    }    
    sort(a+1,a+len+1);
    rep(i,1,n)vis1[i]=0;
    rep(i,1,m)vis2[i]=0;
    int cnt1=0,cnt2=0,fre=0;
    rep(_,1,len){
        int i=a[_].ii,j=a[_].jj;
        if(!vis1[i]&&!vis2[j]){
            vis1[i]=1,vis2[j]=1;
            cnt1++,cnt2++;
        }else if(!vis2[j]){
            vis2[j]=1;
            fre=1;
            cnt2++; 
        }else if(!vis1[i]){
            vis1[i]=1;
        }else{
            fre=1;
            vis1[i]=1;
        }
//        printf("When _=%d,i=%d,j=%d,cnt1=%d,cnt2=%d\n",_,i,j,cnt1,cnt2);
        if(cnt2==m&&(cnt1<m||fre)){
            printf("%d\n",a[_].val);
            return;
        }
    }
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}