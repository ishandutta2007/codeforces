#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int n;
set<int>Set[101000];
long long res = 0;
int main(){
    int i, a;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        Set[a].insert(i);
    }
    int pv = 1, c = 1;
    for(i=1;i<=100000;i++){
        if(Set[i].empty())continue;
        auto it = Set[i].lower_bound(pv);
        if(it == Set[i].end()){
            pv = 1;
            c++,i--;
            continue;
        }
        pv = (*it)+1;
        res += c;
        Set[i].erase(it);
        i--;
    }
    printf("%lld\n",res);
}