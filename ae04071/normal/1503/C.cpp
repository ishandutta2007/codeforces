#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d",&n);

    vector<pair<int,int>> arr;
    long long ans=0;
    for(int i=0;i<n;i++) {
        int a,c;
        scanf("%d%d",&a,&c);
        
        arr.push_back({a, 0});
        arr.push_back({a+c, 1});
        ans += c;
    }
    sort(arr.begin(),arr.end());

    int cnt=0, prev=arr[0].first;
    for(auto &v:arr) {
        if(v.second == 0) {
            if(!cnt) ans += v.first - prev;
            cnt++;
        } else {
            prev = v.first;
            cnt--;
        }
    }
    printf("%lld\n",ans);

    return 0;
}