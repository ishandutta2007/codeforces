#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==-1) for(int j=0;j<=i;j++) a[j]=0;
    }
    reverse(a.begin(),a.end());
    priority_queue<int,vector<int>,greater<int>> q;
    int now=0;
    int sum=1;
    int e=1;
    long long res=0;
    while(sum<n)
    {
        while(now<sum) q.push(a[now++]);
        res+=q.top();
        q.pop();
        sum+=n/(1<<(e++));
    }
    printf("%I64d\n",res);
    return 0;
}