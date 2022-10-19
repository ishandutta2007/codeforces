#include <bits/stdc++.h>
using namespace std;
const int N=102;

int n;
int a[N][3];

int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<3;++j)
        {
            cin>>a[i][j];
        }
    }
    for(int j=0;j<3;++j)
    {
        int sum=0;
        for(int i=0;i<n;++i)
        {
            sum+=a[i][j];
        }
        if(sum!=0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}