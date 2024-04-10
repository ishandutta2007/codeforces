#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int TC;
void Solve(){
    long long K;
    scanf("%lld",&K);
    if(K%2){
        puts("-1");
        return;
    }
    vector<int>Z;
    K/=2;
    int pv = 60, i;
    while(pv>=0){
        long long t = (1ll<<(pv+1)) - 1;
        if(t>K){
            pv--;
            continue;
        }
        Z.push_back(1);
        K-=t;
        for(i=0;i<pv;i++)Z.push_back(0);
    }
    printf("%d\n",Z.size());
    for(auto &t : Z)printf("%d ",t);
    puts("");
}
int main(){
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}