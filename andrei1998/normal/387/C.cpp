#include <iostream>
#include <utility>
#include <cstring>

using namespace std;

int main()
{
    char sir[100005];
    cin.get(sir,100005);

    int n,i,poz=0;
    int ans=0;
    n=strlen(sir);

    pair<int,int> v[100005];
    for(i=0;i<n;i++)
        if(sir[i]>='1' && sir[i]<='9')
        {
            poz++;
            v[poz].first=sir[i]-'0';
            v[poz].second=1;
        }
        else
            v[poz].second++;
    n=poz;

    pair<int,int> curent=v[1];
    int cate=1;

    for(i=2;i<=n;i++)
    {
        if(curent.second>v[i].second)
        {
            cate++;
            curent.second+=v[i].second;
        }
        else if(curent.second==v[i].second)
        {
            if(curent.first>=v[i].first)
            {
                cate++;
                curent.second+=v[i].second;
            }
            else
            {
                ans+=cate;
                cate=1;
                curent.second+=v[i].second;
            }
        }
        else
        {
            ans+=cate;
            cate=1;
            curent.second+=v[i].second;
        }
    }

    cout<<n-ans<<'\n';
    return 0;
}