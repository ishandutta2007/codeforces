#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    //freopen("m.inp","r",stdin);
    //freopen("m.out","w",stdout);
    int n;
    string s;
    cin>>n>>s;
    int i=0,d=0,t=0,m=0,t2=0,d2,t3=1;
    while (i<n)
    {
        if (t3==1) {
        while (i<n && s[i]=='S') i++;
        if (i>=n) break;
        while (i<n && s[i]=='G')
        {
            d++;
            i++;
        }
        t++;
        if (d>=m)
        {
            m=d;
            t2=1;
        }
        if (i>=n) break;
        if (s[i+1]=='G')
        {
            t3=2;
            d2=d;
        }
        else t3=1;
        d=0;
        }
        else
        {
            i++;
            while (i<n && s[i]=='G')
            {
                d++;
                i++;
            }
            t++;
            if (d+d2>m)
            {
                m=d+d2;
                t2=2;
            }
            if (i>=n) break;
            if (s[i+1]=='G')
            {
                t3=2;
                d2=d;
            }
            else t3=1;
            d=0;
        }
    }
    if (t>t2 && m<n) m++;
    cout<<m;
    return 0;
}