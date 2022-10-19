#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=100005;

int n;
char a[N];

bool stg(int m)
{
    bool c[26]={};
    int t[26]={};
    for(int i=0;i<m;++i)
        t[a[i]-'a']++;
    for(int j=0;j<26;++j)
        if(!t[j])
            c[j]=true;
    for(int i=m;i<n;++i)
    {
        t[a[i]-'a']++;
        t[a[i-m]-'a']--;
        for(int j=0;j<26;++j)
            if(!t[j])
                c[j]=true;
    }
    for(int j=0;j<26;++j)
        if(!c[j])
            return true;
    return false;
}

int byn()
{
    int l=1,r=n;
    while((r-l)>3)
    {
        int m=(l+r)/2;
        if(stg(m))
            r=m;
        else
            l=m;
    }
    for(int m=l;m<=r;++m)
        if(stg(m))
            return m;
}

int main()
{
    //freopen("input.txt","r",stdin);
    cin>>a;
    n=strlen(a);
    cout<<byn()<<endl;
    return 0;
}