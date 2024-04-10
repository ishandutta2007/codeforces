#include <iostream>
using namespace std;
int a,b,c,n,a1,b1,c1;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>c;
        a1+=a;
        b1+=b;
        c1+=c;
    }
    if(!a1 && !b1 && !c1)
        cout<<"YES";
    else
        cout<<"NO";    

    return 0;
}