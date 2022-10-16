#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

pair<int,int> v[5005];

int main()
{
    int n=0;
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>v[i].first>>v[i].second;
    sort(v+1,v+n+1);

    int last=0;
    for(int i=1;i<=n;i++)
        if(v[i].second>=last)
            last=v[i].second;
        else
            last=v[i].first;

    cout<<last<<'\n';
    return 0;
}