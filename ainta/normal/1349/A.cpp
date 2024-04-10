#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int n, w[101000];
vector<int>G[201000];
map<int,int>Map;
int main(){
    int i, j;
    for(i=2;i<=200000;i++){
        if(!G[i].empty())continue;
        for(j=i;j<=200000;j+=i){
            G[j].push_back(i);
        }
    }
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        for(auto &t : G[w[i]]){
            Map[t]++;
        }
    }
    long long res=1;
    for(auto &t : Map){
        if(t.second<n-1)continue;
        vector<int>V;
        int x = t.first;
        for(j=1;j<=n;j++){
            int z = w[j] ,c=0;
            while(z%x==0)z/=x,c++;
            V.push_back(c);
        }
        sort(V.begin(),V.end());
        for(j=0;j<V[1];j++){
            res=res*x;
        }
    }
    printf("%lld\n",res);
}