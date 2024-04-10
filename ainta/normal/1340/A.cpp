#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int n, w[101000], P[101000], UF[101000], C[101000];
int Find(int a){
    if(a==UF[a])return a;
    return UF[a] = Find(UF[a]);
}
void Solve(){
    int i;
    multiset<int>Set;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        P[w[i]]=i;
        UF[i]=i;
        C[i] = 1;
        Set.insert(1);
    }
    UF[n+1]=n+1;
    C[n+1]=0;
    for(i=1;i<=n;i++){
        int a = P[i];
        if(C[a]!=*Set.rbegin()){
            puts("No");
            return;
        }
        int x = Find(a+1);
        Set.erase(Set.find(C[a]));
        UF[a]=x;
        if(x!=n+1){
            Set.erase(Set.find(C[x]));
            C[x]+=C[a];
            Set.insert(C[x]);
        }
    }
    puts("Yes");
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}