#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=35;

int n, k;
int a[N];
set<int> taken;

int32_t main()
{
    IOS;
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        cin>>a[i];
        taken.insert(a[i]);
    }
    for(int i=1;i<=k;i++)
    {
        cout<<a[i]<<" ";
        for(int reqd=1, j=1;reqd<n;reqd++)
        {
            while(taken.find(j)!=taken.end())
                j++;    
            cout<<j<<" ";
            taken.insert(j);
        }
        cout<<endl;
    }
    return 0;
}