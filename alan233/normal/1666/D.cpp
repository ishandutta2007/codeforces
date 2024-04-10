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

char s[114514],t[114514];
int las[26];
int n,m;

void solve(){
    scanf("%s%s",s+1,t+1);
    n=strlen(s+1),m=strlen(t+1);
    memset(las,0,sizeof(las));
    int j=m,flag=1;
    for(int i=n;i>=1;i--){
        las[s[i]-'A']++;
        if(j>=1&&s[i]==t[j]){
            if(las[s[i]-'A']!=1){
                flag=0;
                break;
            }
            las[s[i]-'A']=0;
            j--;
        }
    }
    puts(j==0&&flag?"YES":"NO");
}

int main(){
    int T;
    for(scanf("%d",&T);T;T--){
        solve();
    }
    return 0;
}