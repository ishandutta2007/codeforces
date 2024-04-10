#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n;
long long W;
struct point{
    long long a;
    int b;
    bool operator <(const point &p)const{
        return a<p.a;
    }
}w[301000];
void Solve(){
    int i;
    scanf("%d%lld",&n,&W);
    for(i=1;i<=n;i++){
        scanf("%lld",&w[i].a);
        w[i].b=i;
    }
    sort(w+1,w+n+1);
    long long s=0;
    vector<int>V;
    for(i=n;i>=1;i--){
        if(s+w[i].a <= W){
            s+=w[i].a;
            V.push_back(w[i].b);
        }
    }
    if(s*2>=W){
        printf("%d\n",V.size());
        for(auto &t : V)printf("%d ",t);
        puts("");
    }
    else{
        puts("-1");
    }
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}