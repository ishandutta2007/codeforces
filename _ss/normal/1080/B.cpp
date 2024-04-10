#include <iostream>

using namespace std;

int main()
{
    int q;
    long long l,r,l1,r1,l2,r2,t1,t2;
    cin>>q;
    for (int i=1;i<=q;i++)
    {
        cin>>l>>r;
        if (l%2==0)
        {
            l1=l;
            l2=l+1;
        }
        else
        {
            l1=l+1;
            l2=l;
        }
        if (r%2==0)
        {
            r1=r;
            r2=r-1;
        }
        else
        {
            r1=r-1;
            r2=r;
        }
        if (l1<=r1) t1=((l1+r1)/2)*(((r1-l1)/2)+1); else t1=0;
        if (l2<=r2) t2=((l2+r2)/2)*(((r2-l2)/2)+1); else t2=0;
        cout<<t1-t2<<endl;
        //cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
    }
    return 0;
}