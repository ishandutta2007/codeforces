#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n,arr[200000];
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",arr+i);

    multiset<int> tr;
    for(int i=0,v;i<n;i++) {
        scanf("%d",&v);
        tr.insert(v);
    }
    for(int i=0;i<n;i++) {
        auto it=tr.lower_bound((n-arr[i])%n);
        if(it==tr.end()) it=tr.begin();
        printf("%d ",(arr[i]+*it)%n);
        tr.erase(it);
    }
    return 0;
}