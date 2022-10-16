// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mset(s,t) memset(s,t,sizeof(s))
#define mcpy(s,t) memcpy(s,t,sizeof(t))
#define SZ(x) ((int)x.size())
#define pb push_back
#define eb emplace_back
#define fir first
#define sec second

template<class T1,class T2>bool ckmax(T1 &a,T2 b){if(a<b)return a=b,1;else return 0;}
template<class T1,class T2>bool ckmin(T1 &a,T2 b){if(a>b)return a=b,1;else return 0;}

inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<typename T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<typename T>void print(T x,char ch){
    print(x),putchar(ch);
}

const int N=305;

char a[N][N],b[N][N];
int n,num;

bool flag;
void check(string ord){
    if(flag)return;
    rep(i,1,n)rep(j,1,n)b[i][j]=a[i][j];
    int fail=0;
    rep(i,1,n)rep(j,1,n)if(a[i][j]!='.'&&ord[(i+j)%3]!='.'&&a[i][j]!=ord[(i+j)%3]){
        b[i][j]=ord[(i+j)%3];
        fail++;
    }
    if(fail<=num/3){
        flag=1;
        rep(i,1,n){
            rep(j,1,n)putchar(b[i][j]);
            puts("");
        }
        return;
    }
}

void solve(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%s",a[i]+1);
    num=0;
    rep(i,1,n)rep(j,1,n)if(a[i][j]!='.')num++;
    flag=0;
    check(".OX"),check(".XO"),check("X.O"),check("O.X"),check("XO."),check("OX.");
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}