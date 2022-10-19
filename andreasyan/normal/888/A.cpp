#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=100005;

int n;
int a[N];

int main()
{
    //freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    int ans=0;
    for(int i=1;i<n-1;++i)
    {
        if((a[i]<a[i-1] && a[i]<a[i+1]) || (a[i]>a[i-1] && a[i]>a[i+1]))
            ++ans;
    }
    cout<<ans<<endl;
    return 0;
}