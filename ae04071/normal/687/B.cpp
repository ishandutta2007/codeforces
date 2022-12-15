#include <bits/stdc++.h>
using namespace std;

int n,k,a[1000000];
int main() {
    vector<pair<int,int>> pc;
    vector<int> cnt;
    scanf("%d%d",&n,&k);
    for(int i=2;i*i<=k;i++) if(k%i==0) {
        int c=0;
        while(k%i==0) k/=i,c++;
        pc.push_back({i,c});
    }
    if(k>1) pc.push_back({k,1});
    cnt.resize(pc.size(),0);
    
    for(int i=0;i<n;i++) {
        scanf("%d",a+i);
        for(int j=0;j<(int)pc.size();j++) {
            auto &v=pc[j];
            if(a[i]%v.first==0) {
                int c=0;
                while(a[i] % v.first==0) c++,a[i] /= v.first;
                cnt[j] = max(cnt[j], c);
            }
        }
    }

    int f=1;
    for(int i=0;i<(int)pc.size();i++) if(cnt[i] < pc[i].second) {
        f=0;
    }
    puts(f ? "Yes" : "No");
    
    return 0;
}