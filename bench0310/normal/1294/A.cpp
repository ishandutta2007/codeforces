#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        vector<int> v(3);
        int n;
        int sum=0;
        for(int i=0;i<3;i++)
        {
            scanf("%d",&v[i]);
            sum+=v[i];
        }
        scanf("%d",&n);
        sum+=n;
        sort(v.begin(),v.end());
        if((sum%3)==0&&(n>=2*v[2]-v[1]-v[0])) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}