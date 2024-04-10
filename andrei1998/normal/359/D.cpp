#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

int v[300005],st[300005],dr[300005];
bitset<300005> viz;

int main()
{
    int n,i,j;

    cin>>n;

    cin>>v[1];
    st[1]=1;
    for(i=2;i<=n;i++)
    {
        cin>>v[i];
        for(j=i-1;j>=1;j-=st[j])
            if(v[j]%v[i]!=0)
                break;
        st[i]=i-j;
    }

    dr[n]=1;
    for(i=n-1;i>=1;i--)
    {
        for(j=i+1;j<=n;j+=dr[j])
            if(v[j]%v[i]!=0)
                break;
        dr[i]=j-i;
    }

    vector<int> rasp;
    rasp.clear();
    int lung_max=0;

    for(i=1;i<=n;i++)
    {
        if((st[i]+dr[i]-1)>lung_max)
        {
            lung_max=st[i]+dr[i]-1;
            rasp.clear();
            rasp.push_back(i-st[i]+1);
        }
        else if((st[i]+dr[i]-1)==lung_max)
            rasp.push_back(i-st[i]+1);
    }

    vector<int>::iterator it;
    for(it=rasp.begin();it!=rasp.end();it++)
        viz[*it]=1;

    int cate=0;
    for(i=1;i<=n;i++)
        if(viz[i])
            cate++;

    cout<<cate<<' '<<lung_max-1<<'\n';
    for(i=1;i<=n;i++)
        if(viz[i])
            cout<<i<<' ';
    cout<<'\n';

    return 0;
}