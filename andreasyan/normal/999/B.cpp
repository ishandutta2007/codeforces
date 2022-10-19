#include <bits/stdc++.h>
using namespace std;
const int N=102;

int n;
char a[N];

int main()
{
    cin>>n>>a;
    for(int x=1;x<=n;++x)
    {
        if(n%x==0)
        {
            string s;
            for(int i=0;i<x;++i)
                s+=a[i];
            reverse(s.begin(),s.end());
            for(int i=0;i<x;++i)
                a[i]=s[i];
        }
    }
    cout<<a<<endl;
    return 0;
}