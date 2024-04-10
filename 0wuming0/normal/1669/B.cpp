#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            mp[a]++;
        }
        for(auto pr:mp)
        {
            if(pr.second>=3)
            {
                printf("%d\n",pr.first);
                goto ne;
            }
        }
        printf("%d\n",-1);
        ne:;
    }
    return 0;
}