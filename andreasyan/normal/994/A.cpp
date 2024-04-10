#include <bits/stdc++.h>
using namespace std;
const int N=12;

int n,m;
int a[N],b[N];

bool c[N];
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int j=0;j<m;++j)
        cin>>b[j];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(a[i]==b[j])
                c[i]=true;
        }
    }
    for(int i=0;i<n;++i)
        if(c[i])
            cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}