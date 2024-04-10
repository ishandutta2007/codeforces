#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
long long BS = 4e9;
map<int,int>Map1, Map2;
map<long long,int>Map3;
int n;
int main(){
    int i, x, y;
    long long t, Res = 0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&x,&y);
        t=x*BS+y;
        Res += Map1[x]+Map2[y]-Map3[t];
        Map1[x]++,Map2[y]++,Map3[t]++;
    }
    printf("%lld\n",Res);
}