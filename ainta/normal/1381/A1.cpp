#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n;
char p[1010], q[1010];
void Solve(){
    int i;
    scanf("%d",&n);
    scanf("%s",p);
    scanf("%s",q);
    vector<int>T;
    for(i=0;i<n;i++){
        if(p[i]!=q[i]){
            T.push_back(i+1);
            T.push_back(1);
            T.push_back(i+1);
        }
    }
    printf("%d ",T.size());
    for(auto &x : T)printf("%d ",x);
    puts("");
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}