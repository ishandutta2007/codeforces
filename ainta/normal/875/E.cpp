#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int n, s1, s2, w[101000], Nxt[101000], S[101000];
struct point{
    int x, num;
    bool operator<(const point &p)const{
        return x<p.x;
    }
}P[101000];
bool Pos(int K){
    int i;
    int pv = 1;
    set<int>Set;
    if(K==2){
        int t = -1;
    }
    for(i=1;i<=n;i++)Nxt[i] = n+1, S[i] = 0;
    for(i=1;i<=n;i++){
        while(pv<=n && P[pv].x + K < P[i].x){
            Set.insert(P[pv].num);
            pv++;
        }
        auto it = Set.lower_bound(P[i].num);
        if(it != Set.end())Nxt[P[i].num] = min(Nxt[P[i].num], *it);
    }
    Set.clear();
    pv = n;
    for(i=n;i>=1;i--){
        while(pv>=1 && P[pv].x - K > P[i].x){
            Set.insert(P[pv].num);
            pv--;
        }
        auto it = Set.lower_bound(P[i].num);
        if(it != Set.end())Nxt[P[i].num] = min(Nxt[P[i].num], *it);
    }
    int st = max(Nxt[1],Nxt[2]);
    S[3]++, S[st]--;
    int s = 0;
    for(i=3;i<=n;i++){
        s += S[i];
        if(!s)continue;
        S[i+1]++,S[Nxt[i]]--;
    }
    return s>0;
}
int main(){
    int i, b = 0, e = 1000000000, r = 0, mid;
    scanf("%d%d%d",&n,&s1,&s2);
    P[1] = {s1,1};
    P[2] = {s2,2};
    n+=2;
    for(i=3;i<=n;i++){
        scanf("%d",&w[i]);
        P[i] = {w[i],i};
    }
    sort(P+1,P+n+1);
    while(b<=e){
        mid = (b+e)>>1;
        if(Pos(mid)){
            r = mid;
            e = mid - 1;
        }
        else b = mid + 1;
    }
    printf("%d\n",max(r,abs(s1-s2)));
}