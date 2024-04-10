// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) ((int)x.size())
#define pii pair<int,int>
template<class T1,class T2>void ckmin(T1&x,T2 y){if(x>y)x=y;}
template<class T1,class T2>void ckmax(T1&x,T2 y){if(x<y)x=y;}
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

const int N=200005;

char s[N][10];
bool vis2[26][26],vis3[26][26][26];
int l[N],n,ok;

void solve(){
    memset(vis2,0,sizeof(vis2)),memset(vis3,0,sizeof(vis3));
    scanf("%d",&n),ok=0;
    rep(i,1,n){
        scanf("%s",s[i]+1),l[i]=strlen(s[i]+1);
        rep(j,1,l[i])s[i][j]-='a';
        rep(j,1,3)if(l[i]==j&&s[i][1]==s[i][j])ok=1;
    }    
    rep(i,1,n){
        if(l[i]==2){
            if(vis2[s[i][2]][s[i][1]])ok=1;
            rep(j,0,25)if(vis3[s[i][2]][s[i][1]][j])ok=1;
            vis2[s[i][1]][s[i][2]]=1;
        }
        if(l[i]==3){
            if(vis2[s[i][3]][s[i][2]])ok=1;
            if(vis3[s[i][3]][s[i][2]][s[i][1]])ok=1;
            vis3[s[i][1]][s[i][2]][s[i][3]]=1;
        }
    }
    puts(ok?"YES":"NO");
}

int main(){
    int T;
    for(scanf("%d",&T);T;T--)solve();
    return 0;
}