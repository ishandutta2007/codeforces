#include<stdio.h>
#include<algorithm>
#include<set>
#include<map>
#define SIT set<int>::iterator
using namespace std;
int n, Q, X[201000];
set<int>Set;
map<int,int>Map;
int Go(int x, int L){
    SIT it;
    if(L<0){
        it = Set.lower_bound(x+L);
        return *it;
    }
    it = Set.lower_bound(x+L+1);
    it--;
    return *it;
}
int Do(int x, int L){
    SIT it;
    int t, k, t2;
    if(L<0){
        t = Go(x, L);
        L = (-L) - (x - t);
        t2 = Go(t,L);
        if(t==t2)return t;
        L -= (t2-t);
        k = L / (t2-t);
        if(k&1)return Do(t, L%(t2-t));
        return Do(t2, -(L%(t2-t)));
    }
    t = Go(x, L);
    L = L - (t - x);
    t2 = Go(t,-L);
    if(t==t2)return t;
    L -= (t-t2);
    k = L / (t-t2);
    if(k&1)return Do(t, -(L%(t-t2)));
    return Do(t2, L%(t-t2));
}
int main(){
    int i, a, L;
    scanf("%d%d",&n,&Q);
    for(i=1;i<=n;i++){
        scanf("%d",&X[i]);
        Set.insert(X[i]);
        Map[X[i]] = i;
    }
    while(Q--){
        scanf("%d%d",&a,&L);
        printf("%d\n",Map[Do(X[a],L)]);
    }
}