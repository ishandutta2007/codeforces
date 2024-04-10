#include<stdio.h>
#include<algorithm>
#include<set>
#define SIT set<int>::iterator
using namespace std;
set<int>X, Y;
multiset<int>dx, dy;
int W, H, n;
int main(){
    int i, a, d, t1, t2;
    char pp[3];
    long long Res;
    scanf("%d%d%d",&W,&H,&n);
    X.insert(0);
    X.insert(W);
    Y.insert(0);
    Y.insert(H);
    dx.insert(W);
    dy.insert(H);
    SIT it1, it2;
    multiset<int>::iterator it;
    while(n--){
        scanf("%s",pp);
        scanf("%d",&a);
        if(pp[0]=='V'){
            it1 = X.lower_bound(a);
            it2 = it1;it2--;
            t1 = *it1, t2 = *it2;
            d = t1 - t2;
            dx.erase(dx.find(d));
            X.insert(a);
            dx.insert(t1-a);
            dx.insert(a-t2);
        }
        else{
            it1 = Y.lower_bound(a);
            it2 = it1;it2--;
            t1 = *it1, t2 = *it2;
            d = t1 - t2;
            dy.erase(dy.find(d));
            Y.insert(a);
            dy.insert(t1-a);
            dy.insert(a-t2);
        }
        it = dy.end();it--;
        Res = *it;
        it = dx.end();it--;
        Res = Res *(*it);
        printf("%lld\n",Res);
    }
}