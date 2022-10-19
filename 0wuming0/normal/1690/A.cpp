#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k=(n-3)/3;
        int a1=k+1,a2=k+2,a3=k;
        while(a1+a2+a3!=n)
        {
            if(a1+1<a2)
            {
                a1++;
            }
            else if(a3+1<a1)
            {
                a3++;
            }
            else a2++;
        }
        cout<<a1<<" "<<a2<<" "<<a3<<endl;
    }
    return 0;
}