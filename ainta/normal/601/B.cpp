#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
int n, Q, inp[101000], w[101000];
int p[110][2];
long long Res[110];
struct point{
    int g, x;
    bool operator<(const point &p)const{
        return g<p.g;
    }
}ord[101000];
set<int>Set;
int main(){
    int i, b, e, j, b2, e2;
    set<int>::iterator it, it2;
    scanf("%d%d",&n,&Q);
    for(i=1;i<=n;i++)scanf("%d",&inp[i]);
    for(i=1;i<n;i++)w[i]=abs(inp[i+1]-inp[i]);
    for(i=1;i<=Q;i++){
        scanf("%d%d",&p[i][0],&p[i][1]);
        p[i][1]--;
    }
    Set.insert(0);
    Set.insert(n);
    for(i=1;i<n;i++){
        ord[i].x = i;
        ord[i].g = w[i];
    }
    sort(ord+1,ord+n);
    for(i=n-1;i>=1;i--){
        it = Set.lower_bound(ord[i].x);
        it2 = it;
        it--;
        b = (*it)+1;
        e = (*it2)-1;
        for(j=1;j<=Q;j++){
            b2 = max(b,p[j][0]);
            e2 = min(e,p[j][1]);
            if(b2 <= ord[i].x && ord[i].x <= e2){
                Res[j] += (long long)ord[i].g*(ord[i].x-b2+1)*(e2-ord[i].x+1);
            }
        }
        Set.insert(ord[i].x);
    }
    for(i=1;i<=Q;i++)printf("%lld\n",Res[i]);
}