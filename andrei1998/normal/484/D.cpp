#include <iostream>
#include <algorithm>

#define NMAX 1000005
#define lint long long int
using namespace std;

int n;
int v[NMAX];
int low[NMAX];
int high[NMAX];

lint din[NMAX];

int main()
{
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];

    low[1]=high[1]=1;
    for(int i=2;i<=n;i++){
        if(v[i]>=v[i-1])
            low[i]=low[i-1];
        else
            low[i]=i;

        if(v[i]<=v[i-1])
            high[i]=high[i-1];
        else
            high[i]=i;
    }

    for(int i=2;i<=n;i++){
        din[i]=max(v[i]-v[low[i]]+din[low[i]-1],v[high[i]]-v[i]+din[high[i]-1]);

        if(low[i]!=i)
            din[i]=max(din[i],v[i]-v[low[i]+1]+din[low[i]]);
        if(high[i]!=i)
            din[i]=max(din[i],v[high[i]+1]-v[i]+din[high[i]]);
    }

    cout<<din[n]<<'\n';
    return 0;
}