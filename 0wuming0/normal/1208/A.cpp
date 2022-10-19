#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,n;
        cin>>a>>b>>n;
        n%=3;
        switch(n)
        {
            case 0:cout<<a<<endl;break;
            case 1:cout<<b<<endl;break;
            case 2:cout<<(a^b)<<endl;break;
        }
    }
    return 0;
}
/*

*/