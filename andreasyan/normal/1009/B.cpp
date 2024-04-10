#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=100005;

int n;
char a[N];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("name.in","r",stdin);
    //freopen("name.out","w",stdout);
    cin>>a;
    n=strlen(a);
    int b[3]={};
    int i;
    for(i=0;i<n;++i)
    {
        if(a[i]=='2')
            break;
        if(a[i]=='0')
            b[0]++;
        if(a[i]=='1')
            b[1]++;
    }
    while(b[0]--)
        cout<<0;
    while(b[1]--)
        cout<<1;
    for(int j=i;j<n;++j)
        if(a[j]=='1')
            cout<<a[j];
    for(int j=i;j<n;++j)
        if(a[j]!='1')
            cout<<a[j];
    cout<<endl;
    return 0;
}