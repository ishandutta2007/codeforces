#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct point{
    int a, num;
    bool operator <(const point &p)const{
        return a<p.a;
    }
}w[501000];
vector<int>E[501000];
int n, m, v[501000], D[501000];
int main(){
    int i, j;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&w[i].a);
        w[i].num=i;
    }
    sort(w+1,w+n+1);
    for(i=1;i<=n;i++){
        int x = w[i].num;
        for(auto &y : E[x]){
            v[D[y]]=1;
        }
        for(j=1;v[j];j++);
        D[x]=j;
        for(auto &y : E[x]){
            v[D[y]]=0;
        }
        if(D[x]!=w[i].a){
            puts("-1");
            return 0;
        }
    }
    for(i=1;i<=n;i++)printf("%d ",w[i].num);
    puts("");
}