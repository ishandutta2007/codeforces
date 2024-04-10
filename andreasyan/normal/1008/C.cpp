#include <bits/stdc++.h>
using namespace std;
const int N=100005;

int n;
int a[N];

int ans;
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    int j=n-1;
    for(int i=n-1;i>=0;--i)
    {
        while(1)
        {
            if(j==-1)
                break;
            if(a[i]<=a[j])
                --j;
            else
                break;
        }
        if(j!=-1)
        {
            ans++;
            --j;
        }
    }
    cout<<ans<<endl;
    return 0;
}