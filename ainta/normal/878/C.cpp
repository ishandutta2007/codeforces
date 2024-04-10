#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#define pii pair<int,int>
using namespace std;
set<vector<pii > >Set;
int n, K;
void Ins(vector<pii> V){
    Set.insert(V);
    auto it = Set.find(V);
    int i;
    while(it != Set.begin()){
        auto it2 = it;
        it2--;
        int ck = 0;
        for(i=0;i<K;i++){
            if((*it2)[i].second > (*it)[i].first)ck = 1;
        }
        if(!ck)break;
        else{
            for(i=0;i<K;i++){
                V[i].first = min((*it)[i].first, (*it2)[i].first);
                V[i].second = max((*it)[i].second, (*it2)[i].second);
            }
            V[K].first = (*it)[K].first + (*it2)[K].first;
            Set.erase(it);
            Set.erase(it2);
            Set.insert(V);
            it = Set.find(V);
        }
    }
    while(1){
        auto it2 = it;
        it2++;
        if(it2 == Set.end())break;
        int ck = 0;
        for(i=0;i<K;i++){
            if((*it)[i].second > (*it2)[i].first)ck = 1;
        }
        if(!ck)break;
        else{
            for(i=0;i<K;i++){
                V[i].first = min((*it)[i].first, (*it2)[i].first);
                V[i].second = max((*it)[i].second, (*it2)[i].second);
            }
            V[K].first = (*it)[K].first + (*it2)[K].first;
            Set.erase(it);
            Set.erase(it2);
            Set.insert(V);
            it = Set.find(V);
        }
    }
}
int main(){
    int i, j, k;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++){
        vector<pair<int, int>>V;
        for(j=0;j<K;j++){
            scanf("%d",&k);
            V.push_back({k,k});
        }
        V.push_back({1,0});
        Ins(V);
        printf("%d\n",(*Set.rbegin())[K].first);
    }
}