#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        auto comp=[](array<int,2> a,array<int,2> b){return ((a[1]-a[0]<b[1]-b[0])||((a[1]-a[0]==b[1]-b[0])&&a[0]>b[0]));};
        priority_queue<array<int,2>,vector<array<int,2>>,decltype(comp)> q(comp);
        q.push({1,n});
        vector<int> res(n+1,0);
        for(int i=1;i<=n;i++)
        {
            auto [l,r]=q.top();
            q.pop();
            int m=(l+r)/2;
            res[m]=i;
            if(l<m) q.push({l,m-1});
            if(m<r) q.push({m+1,r});
        }
        for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    }
    return 0;
}