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

char a[108][108];
int n;

int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%s",a[i]+1);
    rep(i,1,n){
        rep(j,1,n-6){
            string t="";
            t+=a[i][j];
            t+=a[i][j+1];
            t+=a[i][j+2];
            t+=a[i][j+3];
            t+=a[i][j+4];
            t+=a[i][j+5];
            t+=a[i][j+6];
            if(t=="theseus"){
                cout<<"YES\n";
                return 0;
            }
        }
    }
    rep(i,1,n-6){
        rep(j,1,n){
            string t="";
            t+=a[i][j];
            t+=a[i+1][j];
            t+=a[i+2][j];
            t+=a[i+3][j];
            t+=a[i+4][j];
            t+=a[i+5][j];
            t+=a[i+6][j];
            if(t=="theseus"){
                cout<<"YES\n";
                return 0;
            }
        }
    }
    rep(i,1,n-6){
        rep(j,1,n-6){
            string t="";
            t+=a[i][j];
            t+=a[i+1][j+1];
            t+=a[i+2][j+2];
            t+=a[i+3][j+3];
            t+=a[i+4][j+4];
            t+=a[i+5][j+5];
            t+=a[i+6][j+6];
            if(t=="theseus"){
                cout<<"YES\n";
                return 0;
            }
        }
    }
    cout<<"NO\n";
}