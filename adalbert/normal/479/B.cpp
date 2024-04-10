#include <bits/stdc++.h>
using namespace std;
long long a[10000],mn,mx,n,k,imx,imn;
vector<pair <long long , long long > > vec;
int main()
{
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=k;i++)
    {
        mn=10000000000;
        mx=0;
        for (int i=1;i<=n;i++)
        {
            if (a[i]>mx)
            {
                mx=a[i];
                imx=i;
            }
            if (a[i]<mn)
            {
                imn=i;
                mn=a[i];
            }
        }
        if (mx!=mn)
        {
            vec.push_back(make_pair(imx,imn));
        }
        a[imx]--;
        a[imn]++;
    }
    mn=10000000000;
        mx=0;
        for (int i=1;i<=n;i++)
        {
            if (a[i]>mx)
            {
                mx=a[i];
                imx=i;
            }
            if (a[i]<mn)
            {
                imn=i;
                mn=a[i];
            }
        }
    cout<<mx-mn<<' '<<vec.size()<<'\n';
    for (int i=0;i<vec.size();i++)
    {
        cout<<vec[i].first<<' '<<vec[i].second<<'\n';
    }

}