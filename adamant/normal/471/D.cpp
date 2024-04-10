#include <bits/stdc++.h>

using namespace std;
#define int long long
main()
{
    //freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,w;
    cin>>n>>w;
    if(w==1)
    {
        cout<<n<<endl;
        return 0;
    }
    vector<int> a(n-1),b(w-1);
    int x,y;
    cin>>x;
    for(int i=1;i<n;i++)
    {
        cin>>y;
        a[i-1]=y-x;
        x=y;
    }
    cin>>x;
    for(int i=1;i<w;i++)
    {
        cin>>y;
        b[i-1]=y-x;
        x=y;
    }

    vector<int> T(n+w-1,-3000000000ll);
    for(int i=0;i<w-1;i++) T[i]=b[i];
    for(int i=0;i<n-1;i++) T[w+i]=a[i];
    int N=T.size();
    //for(int i=0;i<N;i++) cout<<T[i]<<' ';
    //cout<<endl;
    vector<int> Z(N);
    int l=0,r=0;
    int ans=0;
    for(int i=1;i<N;i++)
    {
        if(i<=r)
            Z[i]=min(Z[i-l],r-i);
        while(i+Z[i]<N && T[Z[i]]==T[i+Z[i]]) Z[i]++;
        if(i+Z[i]-1>r)
            l=i, r=i+Z[i]-1;
        if(Z[i]==w-1) ans++;
        //cout<<i<<' '<<Z[i]<<endl;
    }

    cout<<ans<<endl;
}