#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for (int i = 0; i < int(n); i++)
typedef pair<int, int> pii;
int n;
set<pii>a[3];
int ans[200010],t;
int main(){
    scanf("%d", &n);
    forn(i, n)scanf("%d", &t),a[t % 3].insert(make_pair(t,i));
    int cur=0;
    forn(i,n){
        set<pii>::iterator it=a[cur % 3].lower_bound(make_pair(cur,-1));  
        pii c;
        if (it!=a[cur % 3].end()&&(*it).first==cur)c = *(it),ans[i] = c.second + 1;
        else {
            if (it == a[cur % 3].begin()) {
                puts("Impossible");
                return 0;
            } else it--,c=*(it),ans[i] = c.second + 1;
        }       
        a[cur % 3].erase(c),cur = c.first + 1;
    }
    puts("Possible");
    forn(i, n)printf("%d ", ans[i]);
    return 0;
}