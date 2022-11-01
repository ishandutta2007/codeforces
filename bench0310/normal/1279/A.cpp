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
        sort(v.begin(),v.end());
        if(v[0]+v[1]>=v[2]-1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}