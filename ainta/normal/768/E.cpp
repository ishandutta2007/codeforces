#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
/*map<long long,int>Map[62];
int Do(int a, long long mask){
    if(!a)return 1;
    if(Map[a][mask])return Map[a][mask];
    int i, v[63]={0,};
    for(i=1;i<=a;i++){
        if((1ll << i) & mask)continue;
        v[Do(a - i, mask | (1ll<<i)) - 1] = 1;
    }
    for(i=0;i<=a;i++)if(!v[i])break;
    return i+1;
}*/
int D[100], cnt, n, a, r;
int main(){
    int i, j;
    for(i=0;i<12;i++){
        for(j=1;j<=i+1;j++)D[cnt++] = i;
    }
    scanf("%d",&n);
    while(n--){
        scanf("%d",&a);
        r^=D[a];
    }
    if(!r)printf("YES\n");
    else printf("NO\n");
}