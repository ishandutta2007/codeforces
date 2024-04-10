#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int w[110];
void Solve(){
    int n;
    scanf("%d",&n);
    int i, j;
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    map<int,int>Map;
    for(i=1;i<n;i++){
        for(j=i+1;j<=n;j++){
            if(w[i]!=w[j]){
                Map[abs(w[i]-w[j])]++;
            }
        }
    }
    printf("%d\n",Map.size());
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}