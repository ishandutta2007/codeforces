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

char a[500005];
int n;

void solve(){
    scanf("%d%s",&n,a+1);
    int ans1=0,term=0;
    rep(i,1,n){
        if(a[i]=='('){
            if(i<n){
                i++;
                ans1++;
                term=i;
            }
        }else{
            int j=i+1;
            while(j<=n&&a[j]!=')')j++;
            if(j<=n){
                ans1++;
                term=j;
                i=j;
            }else{
                break;
            }
        }
    }
    printf("%d %d\n",ans1,n-term);
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}