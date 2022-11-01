#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        vector<int> v={n};
        int k=1;
        while((n/k)>0)
        {
            int l=k,r=n+1;
            while(l<r-1)
            {
                int m=(l+r)/2;
                if((n/m)<(n/k)) r=m;
                else l=m;
            }
            k=r;
            v.push_back(n/k);
        }
        reverse(v.begin(),v.end());
        printf("%d\n",(int)v.size());
        for(int a:v) printf("%d ",a);
        printf("\n");
    }
    return 0;
}