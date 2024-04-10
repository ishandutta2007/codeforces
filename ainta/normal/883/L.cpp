#include<cstdio>
#include<algorithm>
#include<set>
#include<queue>
#define pli pair<long long,int>
#define N_ 201000
using namespace std;
int n, K, m;
multiset<int>AV;
set<pli>V[N_];
struct point{
    int num, x;
    long long T;
    bool operator<(const point &p)const{
        return T>p.T;
    }
};
priority_queue<point>PQ;
void POP(long long T){
    while(!PQ.empty()){
        point tp = PQ.top();
        if(tp.T > T)break;
        PQ.pop();
        AV.insert(tp.x);
        V[tp.x].insert({tp.T, tp.num});
    }
}
int main(){
    int i, x;
    scanf("%d%d%d",&n,&K,&m);
    for(i=1;i<=K;i++){
        scanf("%d",&x);
        PQ.push({i,x,0});
    }
    long long T;
    int a, b;
    for(i=0;i<m;i++){
        scanf("%lld%d%d",&T,&a,&b);
        POP(T);
        if(AV.empty()){
            POP(PQ.top().T);
        }
        auto it = AV.lower_bound(a);
        int M = 1e9, x;
        pli tp;
        if(it != AV.end()){
            x = *it;
            M = abs(x - a);
            tp = *V[x].begin();
        }
        if(it != AV.begin()){
            it--;
            int x2 = *it;
            if(M > abs(x2-a) || (M==abs(x2-a) && *V[x2].begin() < tp))M = abs(x2-a), x = x2, tp = *V[x2].begin();
        }
        printf("%d %lld\n",tp.second, M + max(T, tp.first) - T);
        PQ.push({tp.second, b, M + max(T, tp.first) + abs(b-a)});
        V[x].erase(V[x].begin());
        AV.erase(AV.find(x));
    }
}