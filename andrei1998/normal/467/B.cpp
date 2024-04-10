#include <iostream>

using namespace std;

inline bool diff(int a,int b,int n,int k){
    int rez=0;
    for(int i=0;i<n;i++)
        rez+=(((bool)(a&(1<<i)))!=((bool)(b&(1<<i))));

    return (rez<=k);
}

int main()
{
    int v[1005];
    int n,m,k;

    cin>>n>>m>>k;
    for(int i=1;i<=(m+1);i++)
        cin>>v[i];

    int ans=0;
    for(int i=1;i<=m;i++)
        ans+=diff(v[m+1],v[i],n,k);

    cout<<ans<<endl;
    return 0;
}