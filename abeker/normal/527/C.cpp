#include <cstdio>
#include <set>
using namespace std;

typedef long long ll;

set <int> X, Y;
multiset <int> lx, ly;

int main() {
    int W, H, N;
    scanf("%d%d%d", &W, &H, &N);
    
    X.insert(0);
    X.insert(W);
    Y.insert(0);
    Y.insert(H);
    lx.insert(W);
    ly.insert(H);
    
    while (N--) {
        char c;
        int a;
        scanf(" %c%d", &c, &a);
        if (c == 'H') { 
            Y.insert(a);
            set <int> :: iterator it = Y.find(a);
            int lo = *(--it); it++;
            int hi = *(++it);
            ly.erase(ly.find(hi - lo));
            ly.insert(a - lo);
            ly.insert(hi - a);  
        }
        else {
            X.insert(a);
            set <int> :: iterator it = X.find(a);
            int lo = *(--it); it++;
            int hi = *(++it);
            lx.erase(lx.find(hi - lo));
            lx.insert(a - lo);
            lx.insert(hi - a);  
        }
        printf("%I64d\n", (ll)(*(--lx.end())) * (*(--ly.end())));
    }
    
    return 0;
}