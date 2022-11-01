#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        vector<int> a(n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        vector<array<int,2>> v(n/2);
        vector<int> cnt(2*k+1,0);
        for(int i=0;i<n/2;i++)
        {
            cnt[a[i]+a[n-i-1]]++;
            v[i]={min(a[i],a[n-i-1])+1,max(a[i],a[n-i-1])+k};
        }
        sort(v.begin(),v.end());
        int res=n;
        priority_queue<int,vector<int>,greater<int>> q;
        int idx=0;
        for(int x=1;x<=2*k;x++)
        {
            while(idx<n/2&&v[idx][0]==x) q.push(v[idx++][1]);
            int one=q.size()-cnt[x];
            int two=n/2-cnt[x]-one;
            res=min(res,one+2*two);
            while(!q.empty()&&q.top()==x) q.pop();
        }
        printf("%d\n",res);
    }
    return 0;
}