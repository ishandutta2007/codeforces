#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int N=200003;

int n;
int a[N];
int p[N];
string s,s1;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    cin>>s1;
    s+='0';
    s+=s1;
    s+='0';
    int l,r;
    for(int i=1;i<=n;++i)
    {
        if(s[i]=='1' && s[i-1]=='0')
            l=i;
        if(s[i]=='0' && s[i-1]=='1')
        {
            r=i;
            sort(a+l,a+r+1);
        }
    }
    for(int i=1;i<=n;++i)
        if(a[i]!=i)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    cout<<"YES"<<endl;
    return 0;
}