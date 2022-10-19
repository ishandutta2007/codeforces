#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N=100003;

int n;
int a[N];
vector<int> v;
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    int minu=a[0];
    for(int i=1;i<n;++i)
    {
        minu=min(minu,a[i]);
    }
    for(int i=0;i<n;++i)
        if(a[i]==minu)
            v.push_back(i);
    int ans=99999999;
    for(int i=1;i<v.size();++i)
        ans=min(ans,v[i]-v[i-1]);
        cout<<ans<<endl;
    return 0;
}