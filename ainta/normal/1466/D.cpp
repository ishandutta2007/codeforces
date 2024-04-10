#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, w[101000], Deg[101000];
void Solve(){
    int i;
    scanf("%d",&n);
    long long s=0;
    for(i=1;i<=n;i++){
        Deg[i]=0;
        scanf("%d",&w[i]);
        s+=w[i];
    }
    for(i=1;i<n;i++){
        int a, b;
        scanf("%d%d",&a,&b);
        Deg[a]++,Deg[b]++;
    }
    vector<int>V;
    for(i=1;i<=n;i++){
        for(int j=1;j<Deg[i];j++){
            V.push_back(w[i]);
        }
    }
    sort(V.begin(),V.end());
    reverse(V.begin(),V.end());
    for(i=1;i<n;i++){
        printf("%lld ",s);
        if(i!=n-1)s+=V[i-1];
    }
    puts("");
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}