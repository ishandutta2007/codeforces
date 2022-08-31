#include<cstdio>
#include<algorithm>
#include<set>
#include<string>
using namespace std;
int n, cnt, SZ[101000];
#define pii pair<int,int>
string P[101000];
char p[1010000];
struct point{
    int num, t, ck;
    bool operator<(const point &p)const{
        return t<p.t;
    }
}w[2010000];
set<pii>Set;
int main(){
    int i, j, t, L = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",p);
        P[i] = p;
        SZ[i] = P[i].size();
        int c;
        scanf("%d",&c);
        while(c--){
            scanf("%d",&t);
            t--;
            L = max(L, t+SZ[i]);
            w[cnt++] = {i, t, 1};
            w[cnt++] = {i, t+SZ[i], -1};
        }
    }
    sort(w,w+cnt);
    int pv = 0;
    for(i=0;i<L;i++){
        while(pv<cnt && w[pv].t <=i){
            if(w[pv].ck == 1){
                Set.insert(pii(w[pv].num, w[pv].t));
            }
            else{
                Set.erase(pii(w[pv].num, w[pv].t - SZ[w[pv].num]));
            }
            pv++;
        }
        if(Set.empty())printf("a");
        else{
            auto it = Set.begin();
            printf("%c",P[it->first][i - it->second]);
        }
    }
    printf("\n");
}