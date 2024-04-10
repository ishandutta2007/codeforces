#include <iostream>
using namespace std;

int n;
int main()
{
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;++j)
        {
            int k=i^j;
            if(k>=j && k<=n && k<i+j && i<k+j && j<k+i)
                ++ans;
        }
    cout<<ans<<endl;
    return 0;
}