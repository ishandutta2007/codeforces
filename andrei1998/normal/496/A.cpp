#include <iostream>
#include <algorithm>

using namespace std;

int v[105];
int st[105];
int dr[105];

int main()
{
    int n=0;
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>v[i];

    for(int i=2;i<=n;i++){
        st[i]=max(st[i-1],v[i]-v[i-1]);
    }

    for(int i=n-1;i>=1;i--){
        dr[i]=max(dr[i+1],v[i+1]-v[i]);
    }

    int ans=10005;
    for(int i=2;i<n;i++){
        if(max(max(st[i-1],dr[i+1]),v[i+1]-v[i-1])<ans)
            ans=max(max(st[i-1],dr[i+1]),v[i+1]-v[i-1]);
    }

    cout<<ans<<'\n';
    return 0;
}