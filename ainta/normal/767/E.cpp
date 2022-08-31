#include<cstdio>
#include<algorithm>
#include<set>
#define pii pair<int,int>
using namespace std;
int n, m, w[101000], chk[101000];
set<pii>Set;
long long Res;
int main(){
    int i, j, a;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&w[i]);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        if(w[i]%100==0)continue;
        Set.insert(pii((100 - w[i]%100) * a, i));
        m -= w[i]%100;
        if(m < 0){
            Res += Set.begin()->first;
            chk[Set.begin()->second] = 1;
            Set.erase(Set.begin());
            m += 100;
        }
    }
    printf("%lld\n",Res);
    for(i=1;i<=n;i++){
        if(chk[i])printf("%d 0\n",(w[i]+99)/100, 0);
        else printf("%d %d\n",w[i]/100, w[i]%100);
    }
}