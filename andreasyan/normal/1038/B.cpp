#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=1000006;

int n;

int main()
{
    //freopen("input.txt","r",stdin);
    cin>>n;
    if(n<=2)
    {
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    cout<<1<<' '<<n<<endl;
    cout<<n-1;
    for(int i=1;i<n;++i)
        cout<<' '<<i;
    cout<<endl;
    return 0;
}