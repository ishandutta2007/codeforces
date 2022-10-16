#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<pair<int,int> > muchii[100005];
int n,m;

int din[300005];
int aux[300005];

int main()
{
    int a,b,c;

    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b>>c;
        muchii[c].push_back(make_pair(a,b));
    }

    vector<pair<int,int> >::iterator it;
    for(int i=100004;i>0;i--){
        for(it=muchii[i].begin();it!=muchii[i].end();it++)
            aux[it->first]=max(aux[it->first],din[it->second]+1);

        for(it=muchii[i].begin();it!=muchii[i].end();it++)
            din[it->first]=aux[it->first];
    }

    int maxim=0;
    for(int i=1;i<=n;i++){
        if(din[i]>maxim)
            maxim=din[i];
    }

    cout<<maxim<<'\n';
    return 0;
}