#include <cstdio>
#include <vector>

#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug(s) \
debug("Debug : Line %d, Function %s(): %s\n",__LINE__,__FUNCTION__,s)
#else
#define debug(...) 
#define Debug(s) 
#endif

using std::vector;

template<class T>void fr(T &a) {
    T s=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    a=w*s;
}
template<class T>T fr() {T a;fr(a);return a;}
#define R() fr<int>()

const int N=5e5;
struct Node{int dep,id;};
vector<int>E[N+10],tmp[N+10];
vector<Node>q[N+10];
int cnt[N+10],ans[N+10];
char str[N+10];

void Dfs(int u,int dep) {
    cnt[dep]^=1<<(str[u]-'a');
    for(int i=0;i<q[u].size();i++) tmp[u].push_back(cnt[q[u][i].dep]);
    for(int i=0;i<E[u].size();i++) Dfs(E[u][i],dep+1);
    for(int i=0;i<q[u].size();i++)
        ans[q[u][i].id]=(tmp[u][i]^cnt[q[u][i].dep]);
}

int main() {
    int n=R(),m=R();
    for(int i=2;i<=n;i++) E[R()].push_back(i);
    scanf("%s",str+1);
    for(int i=1;i<=m;i++) {
        int x=R(),dep=R();
        q[x].push_back((Node){dep,i});
    }
    Dfs(1,1);
    for(int i=1;i<=m;i++) puts(ans[i]==(ans[i]&(-ans[i]))?"Yes":"No");
    return 0;
}