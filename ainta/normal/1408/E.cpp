#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, A[101000], B[101000], UF[201000];
struct Edge{
    int a, b, c;
    bool operator <(const Edge &p)const{
        return c<p.c;
    }
};
vector<Edge>E;
int Find(int a){
    if(a==UF[a])return a;
    return UF[a]=Find(UF[a]);
}
void Solve(){
    int i;
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++){
        scanf("%d",&A[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&B[i]);
    }
    for(i=1;i<=m;i++){
        int k, a;
        scanf("%d",&k);
        while(k--){
            scanf("%d",&a);
            E.push_back({i,a+m,B[a]+A[i]});
        }
    }
    for(i=1;i<=n+m;i++)UF[i]=i;
    sort(E.begin(),E.end());
    reverse(E.begin(),E.end());
    long long res=0;
    for(auto &t : E){
        if(Find(t.a)!=Find(t.b)){
            UF[Find(t.a)]=Find(t.b);
        }
        else res+=t.c;
    }
    printf("%lld\n",res);
}
int main(){
    int TC = 1;
    while(TC--){
        Solve();
    }
}