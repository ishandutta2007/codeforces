#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int v[3005];

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>v[i];

    vector<pair<int,int> > sol;

    int poz;
    for(int i=1;i<=n;i++){
        poz=i;

        for(int j=i;j<=n;j++)
            if(v[j]<v[poz])
                poz=j;
        swap(v[i],v[poz]);

        if(poz!=i)
        sol.push_back(make_pair(poz,i));
    }

    cout<<sol.size()<<'\n';
    for(int i=0;i<sol.size();i++)
        cout<<sol[i].first-1<<' '<<sol[i].second-1<<'\n';

    return 0;
}