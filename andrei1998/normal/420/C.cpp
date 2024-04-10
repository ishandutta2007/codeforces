#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

#define NMAX 300005
int c[NMAX];
vector<pair<int,int> > v;

int main()
{
    int n,p,i,a,b;
    cin>>n>>p;

    for(i=1;i<=n;i++)
    {
        cin>>a>>b;
        c[a]++;
        c[b]++;

        if(a>b)
            swap(a,b);
        v.push_back(make_pair(a,b));
    }

    pair<int,int> ante=make_pair(0,0);
    long long int rasp=0;
    long long int rasp_fals=0;

    sort(v.begin(),v.end());

    int cxy=0;
    for(i=0;i<v.size();i++)
    {
        if(v[i]==ante)
            cxy++;
        else
        {
            if(ante.first!=0)
                if(c[ante.first]+c[ante.second]-cxy>=p)
                    rasp++;

            if(ante.first!=0)
                if(c[ante.first]+c[ante.second]>=p)
                    rasp_fals++;

            cxy=1;
            ante=v[i];
        }
    }


    if(ante.first!=0)
        if((c[ante.first]+c[ante.second]-cxy)>=p)
            rasp++;

    if(ante.first!=0)
        if(c[ante.first]+c[ante.second]>=p)
            rasp_fals++;
    rasp-=rasp_fals;

    sort(c+1,c+n+1);
    for(i=1;i<n;i++)
    {
        int st=i+1;
        int dr=n;
        int mijl=(n+i+1)>>1;
        int r=n+1;

        while(st<=dr)
        {
            if(c[mijl]+c[i]>=p)
            {
                if(mijl<r)
                    r=mijl;
                dr=mijl-1;
            }
            else
                st=mijl+1;

            mijl=(st+dr)>>1;
        }

        rasp+=(n-r+1);
    }

    cout<<rasp<<'\n';
    return 0;
}