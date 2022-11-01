#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

//ifstream fin("input");

char cit[105];

long long a[3], b[3], p[3];
long long r;

bool verif(long long nr)
{
    long long t=0;
    for(int i=0;i<3;i++)
    {
        if(1LL*a[i]*nr>b[i])
        {
            t+=(1LL*a[i]*nr-b[i])*p[i];
        }
    }
    if(t<=r) return true;
    return false;
}

int main()
{
    int n, i;
    long long st, dr, mid, sol=0;
    cin.getline(cit, 105); n=strlen(cit);
    for(i=0;i<n;i++)
    {
        if(cit[i]=='B') a[0]++;
        else if(cit[i]=='S') a[1]++;
        else a[2]++;
    }
    for(i=0;i<3;i++) cin>>b[i];
    for(i=0;i<3;i++) cin>>p[i];
    cin>>r;
    st=0;dr=r+b[0]+b[1]+b[2];
    while(st<=dr)
    {
        mid=(st+dr)/2;
        if(verif(mid))
        {
            sol=mid;
            st=mid+1;
        }
        else
        {
            dr=mid-1;
        }
    }
    cout<<sol;
}