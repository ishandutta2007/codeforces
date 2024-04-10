#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int n, a;
long long S;
multiset<int>Set;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d",&a);
        if(!Set.empty() && *Set.begin() < a){
            S += (a - *Set.begin());
            Set.erase(Set.begin());
            Set.insert(a);
        }
        Set.insert(a);
    }
    printf("%lld\n",S);
}