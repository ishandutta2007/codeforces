#include <iostream>

using namespace std;

int main()
{
    int q,l,r,d;
    cin>>q;
    for (int i=1;i<=q;i++)
    {
        cin>>l>>r>>d;
        if (d>=l && d<=r)
        {
            if ((r+1)%d!=0) cout<<(((r+1)/d)+1)*d; else cout<<r+1;
        }
        else cout<<d;
        cout<<endl;
    }
    return 0;
}