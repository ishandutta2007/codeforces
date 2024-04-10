#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,k;
    cin>>t>>k;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        if(k==1)
        {
            if((m%2)*(n%2))cout<<'-'<<endl;
            else cout<<'+'<<endl;
            continue;
        }
        n--;
        m--;
        if(n<m)swap(n,m);
        int a,b,c;
        a=m;
        b=n-m;
        c=a/(k+1);
        int x,y;
        x=a-c*k;
        y=a-c*(k+1);
        if(y==k||(x%2+y%2+b)%2)cout<<'+'<<endl;
        else cout<<'-'<<endl;
    }
    return 0;
}