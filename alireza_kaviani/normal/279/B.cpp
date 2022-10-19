#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    
    vector<int> a(n);
    vector<int> vec(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        vec[i]=(i==0?a[i]:a[i]+vec[i-1]);
    }
    
    int ans=0 , sum=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,upper_bound(vec.begin(),vec.end(),sum+m)-(vec.begin()+i));
        sum+=a[i];
    }
    
    cout << ans << endl;
}