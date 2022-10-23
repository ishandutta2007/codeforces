#include <iostream>

using namespace std;

int main()
{
    long long n,q,f[100001],l,r,st[101],k,d,kq2,snt=1000000007,kq3,h,t,kq;
    f[0]=0;
    string s;
    cin>>n>>q;
    cin>>s;
    for (int i=0;i<n;i++)
        if (s[i]=='0') f[i+1]=f[i]; else f[i+1]=f[i]+1;
    for (int i=1;i<=q;i++)
    {
        cin>>l>>r;
        h=f[r]-f[l-1];
        t=r-l+1;
        k=h;
        d=0;
        kq=-1;
        while (k>1)
        {
            d++;
            if (k%2==1)
            {
                k=k-1;
                st[d]=1;
            }
            else
            {
                k=k/2;
                st[d]=2;
            }
        }
        kq2=2;
        for (int i=d;i>=1;i--)
            if (st[i]==1) kq2=(kq2*2)%snt;
            else kq2=(kq2*kq2)%snt;
        kq=(kq+kq2)%snt;
        kq2--;
        kq3=2;
        k=t-h;
        d=0;
        while (k>1)
        {
            d++;
            if (k%2==1)
            {
                k=k-1;
                st[d]=1;
            }
            else
            {
                k=k/2;
                st[d]=2;
            }
        }
        for (int i=d;i>=1;i--)
            if (st[i]==1) kq3=(kq3*2)%snt;
            else kq3=(kq3*kq3)%snt;
        kq2=(kq2*(kq3-1))%snt;
        if (t-h>0) kq=(kq+kq2)%snt;
        if (h==0) kq=0;
        cout<<kq<<endl;
    }
    return 0;
}