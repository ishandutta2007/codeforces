#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        vector<int> v(3);
        for(int i=0;i<3;i++) scanf("%d",&v[i]);
        sort(v.begin(),v.end(),greater<int>());
        int a=min(v[0],v[1]+v[2]);
        printf("%d\n",a+(v[1]+v[2]-a)/2);
    }
    return 0;
}