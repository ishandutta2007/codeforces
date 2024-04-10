#include <bits/stdc++.h>
using namespace std;

int n,a[3],s[5];
int main() {
    scanf("%d",&n);
    for(int i=0;i<3;i++) scanf("%d",a+i);

    multiset<int> tr;
    for(int i=0;i<n;i++) {
        int v;
        scanf("%d",&v);
        tr.insert(v);
        if(v > a[0]+a[1]+a[2]) {
            puts("-1");
            return 0;
        }
    }
    sort(a,a+3);

    s[0]=7; s[1]=6; s[2]=5; s[3]=3,s[4]=4;;
    if(a[0]+a[1]<=a[2]) s[3]=4;
    int i=0,ans=0;
    while(!tr.empty() && i<4) {
        int sum=0;
        for(int j=0;j<3;j++) if(s[i+1]>>j&1) sum += a[j];
        if(*prev(tr.end()) <= sum) {
            i++; continue;
        }
        
        int rem=0;
        sum=0;
        for(int j=0;j<3;j++) {
            if(s[i]>>j & 1) sum += a[j];
            else rem += a[j];
        }
        tr.erase(prev(tr.end()));
        
        auto it = tr.upper_bound(rem);
        if(it!=tr.begin()) {
            it--;tr.erase(it);
        }
        ans++;
    }
    while(!tr.empty()) {
        ans++;
        tr.erase(prev(tr.end()));
        
        int f=0;
        auto it=tr.upper_bound(a[1]);
        if(it!=tr.begin())tr.erase(prev(it)),f=1;
        
        it=tr.upper_bound(a[0]);
        if(it!=tr.begin()) tr.erase(prev(it)),f=1;
        if(!f) {
            it = tr.upper_bound(a[0]+a[1]);
            if(it!=tr.begin()) tr.erase(prev(it));
        }
    }
    printf("%d\n",ans);
    
    return 0;
}