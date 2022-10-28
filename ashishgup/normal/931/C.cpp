#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int v[N];
map<int, int> m;

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        m[v[i]]++;
    }
    sort(v+1, v+n+1);
    if(v[n]-v[1]<=1)
    {
        cout<<n<<endl;
        for(int i=1;i<=n;i++)
            cout<<v[i]<<" ";
        return 0;
    }
    int val=m.begin() -> first;
    int a=m[val];
    int b=m[val+1];
    int c=m[val+2];
    int pos1=2 * (b/2);
    int pos2=2 * min(a, c);
    if(pos1>=pos2)
    {
        cout<<n-pos1<<endl;
        a+=b/2;
        c+=b/2;
        b=b%2;
        for(int i=1;i<=a;i++)
            cout<<val<<" ";
        for(int i=1;i<=b;i++)
            cout<<val+1<<" ";
        for(int i=1;i<=c;i++)
            cout<<val+2<<" ";
    }
    else
    {
        int store=min(a, c);
        a-=store;
        c-=store;
        b+=2*store;
        cout<<n-2*store<<endl;
        for(int i=1;i<=a;i++)
            cout<<val<<" ";
        for(int i=1;i<=b;i++)
            cout<<val+1<<" ";
        for(int i=1;i<=c;i++)
            cout<<val+2<<" ";
    }
    return 0;
}