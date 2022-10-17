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

vector<pii> ans;
int n;

int main(){
    cin>>n;
    if(n==1){
        puts("1\n1 1");
        return 0;
    }
    while(n%3!=2){
        ans.pb({n,n});
        n--;
    }
    int m=2*n/3;
    for(int i=1;i<=(m+1)/2;i++)ans.pb({i,(m+1)/2+1-i});
    for(int i=(m+1)/2+1;i<=m;i++)ans.pb({i,m+1+(m+1)/2-i});
    print(SZ(ans),'\n');
    for(auto [x,y]:ans)
        printf("%d %d\n",x,y);
    return 0;
}

/*
int n,ans=111;

vector<pii> k;
int a[11][11];

void dfs(int x,int y,int step){
    if(y==n+1)x++,y=1;
    if(x==n+1){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(!a[i][j])return;
        ckmin(ans,step);
        if(step==3){
            for(auto [x,y]:k)
                printf("%d %d\n",x,y);
            puts("----");
            // exit(0);
        }
        return;
    }
    bool chk=1;
    for(int i=1;i<=n;i++)if(!a[x][i])chk=0;
    for(int i=1;i<=n;i++)if(!a[i][y])chk=0;
    for(int i=1;i<min(x,y);i++){
        if(!a[x-i][y-i])chk=0;
    }
    for(int i=0;max(x,y)+i<=n;i++){
        if(!a[x+i][y+i])chk=0;
    }
    if(chk){
        dfs(x,y+1,step);
    }else{
        for(int i=1;i<=n;i++)a[x][i]++;
        for(int i=1;i<=n;i++)a[i][y]++;
        for(int i=1;i<min(x,y);i++){
            a[x-i][y-i]++;
        }
        for(int i=0;max(x,y)+i<=n;i++){
            a[x+i][y+i]++;
        }
        k.pb({x,y});
        dfs(x,y+1,step+1);
        for(int i=1;i<=n;i++)a[x][i]--;
        for(int i=1;i<=n;i++)a[i][y]--;
        for(int i=1;i<min(x,y);i++){
            a[x-i][y-i]--;
        }
        for(int i=0;max(x,y)+i<=n;i++){
            a[x+i][y+i]--;
        }
        k.pop_back();
        dfs(x,y+1,step);
    }
}

int main(){
    cin>>n;
    dfs(1,1,0);
    cout<<ans;
}
*/