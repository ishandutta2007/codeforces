#include"bits/stdc++.h"
using namespace std;
bitset<1000>s;
int main()
{
    int n,m;
    cin>>n>>m;
    s[0]=1;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        a%=m;
        if(s[(m-a)%m]==1)
        {
            cout<<"YES"<<endl;
            return 0;
        }
        //for(int i=0;i<10;i++)cout<<s[i];cout<<endl;
        s|=((s<<a)|(s>>(m-a)));
        //s|=((s<<a)|((s<<(1000-m))>>(1000-a)));
    }
    cout<<"NO"<<endl;
    return 0;
}