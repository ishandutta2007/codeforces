#include"bits/stdc++.h"
using namespace std;
int ans[10005];
int nn;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        k--;
        int a=(sqrt(k)-1);
        if(a<0)a=0;
        while(a*a<=k)a++;
        a--;
        k-=a*a;
        k++;
        if(k<=a)
        {
            cout<<k<<" "<<a+1<<endl;
        }
        else
        {
            cout<<a+1<<" "<<a*2+2-k<<endl;
        }
    }
    return 0;
}