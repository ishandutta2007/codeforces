#include <bits/stdc++.h>
using namespace std;
const int N=300005;

int n,m;
int a[N],b[N];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("dices.in","r",stdin);
    //freopen("dices.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<m;++i)
        cin>>b[i];
    int j=0;
    for(int i=0;i<n;++i)
    {
        if(j==m)
            continue;
        if(b[j]>=a[i])
            ++j;
    }
    cout<<j<<endl;
    return 0;
}