#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        vector<int> v(n);
        for(int i=0;i<n;i++) scanf("%d",&v[i]);
        sort(v.begin(),v.end());
        vector<int> res;
        int l=0,r=n-1;
        while(l<=r)
        {
            res.push_back(v[l++]);
            if(l<=r) res.push_back(v[r--]);
        }
        reverse(res.begin(),res.end());
        for(int i=0;i<n;i++) printf("%d%c",res[i]," \n"[i==n-1]);
    }
    return 0;
}