#include <bits/stdc++.h>
using namespace std;
const int N=102;

int n;
char a[N];

int main()
{
    cin>>a;
    n=strlen(a);
    for(int i=0;i<=n-3;++i)
    {
        bool c[3]={};
        for(int j=i;j<i+3;++j)
            if(a[j]>='A' && a[j]<='C')
                c[a[j]-'A']=true;
        bool z=true;
        for(int j=0;j<3;++j)
            if(!c[j])
                z=false;
        if(z)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}