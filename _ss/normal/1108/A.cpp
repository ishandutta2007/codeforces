#include <iostream>

using namespace std;

int main()
{
    int q,l1,r1,l2,r2;
    cin>>q;
    for (int i=1;i<=q;i++)
    {
        cin>>l1>>r1>>l2>>r2;
        if (l1==l2) cout<<l1<<" "<<r2; else cout<<l1<<" "<<l2;
        cout<<endl;
    }
    return 0;
}