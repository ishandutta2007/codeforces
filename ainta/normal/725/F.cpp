#include<stdio.h>
#include<algorithm>
#include<set>
#define pii pair<int,int>
using namespace std;
multiset<pii>Set;
int n;
long long Res;
int main(){
    int i,a,b,c,d;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(a<=d && b <= c){
            continue;
        }
        if(a+b < c+d){
            if(b>c)Res -= b - c;
            else Res += a - d;
        }
        else{
            Set.insert(pii(a+b,a));
            Set.insert(pii(c+d,c));
        }
    }
    while(!Set.empty()){
        auto it = Set.end();it--;
        Res += it->second;
        Set.erase(it);
        if(Set.empty())break;
        it = Set.end();it--;
        Res -= it->first-it->second;
        Set.erase(it);
    }
    printf("%lld\n",Res);
}