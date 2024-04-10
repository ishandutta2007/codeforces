#include"bits/stdc++.h"
using namespace std;
int get(int a,int b,int c,int d)
{
    a=max(a,c);
    d=min(b,d);
    return max(d-a,0);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<max(b,a)-min(a,b)-get(min(a,b),max(b,a),c-d,c+d)<<endl;
    }
    return 0;
}