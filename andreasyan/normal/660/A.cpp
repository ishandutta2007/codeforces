#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N=1003,m=1000000007;

int n;
int a[N];
vector<int> ans;
int gcd(int x,int y)
{
    if(x==0)
        return y;
    if(x>y)
        return gcd(y,x);
    return gcd(y%x,x);
}

int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n-1;++i)
    {
        ans.push_back(a[i]);
        if(gcd(a[i],a[i+1])!=1)
        {
            for(int j=1;j;++j)
                if(gcd(a[i],j)==1 && gcd(a[i+1],j)==1)
                {
                    ans.push_back(j);
                    break;
                }
        }
    }
    ans.push_back(a[n-1]);
    cout<<ans.size()-n<<endl;
    for(int i=0;i<ans.size()-1;++i)
        cout<<ans[i]<<' ';
    cout<<ans.back()<<endl;
    return 0;
}