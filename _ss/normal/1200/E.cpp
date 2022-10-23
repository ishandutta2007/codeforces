#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define dl vector<char>
const ll maxn=1e6+10;
int z[maxn];

int same(dl s1,dl s2)
{
    dl s3;
    int l1=s1.size(),l2=s2.size();
    for (int i=0;i<l1;i++) s3.pb(s1[i]);
    for (int i=0;i<l2;i++) s3.pb(s2[i]);
    int l=0,r=0;
    for (int i=0;i<l1+l2;i++) z[i]=0;
    for (int i=1;i<l1+l2;i++)
    {
        if (i<=r) z[i]=min(z[i-l],r-i+1);
        while (i+z[i]<l1+l2 && s3[z[i]]==s3[i+z[i]]) z[i]++;
        if (i+z[i]-1>r)
        {
            l=i;
            r=i+z[i]-1;
        }
    }
    for (int i=l1;i<l1+l2;i++)
        if (i+z[i]==l1+l2) return z[i];
    return 0;
}

void read(dl &s)
{
    char ch=getchar();
    while (ch!=' ' && ch!='\n' && ch!=-1)
    {
        s.pb(ch);
        ch=getchar();
    }
}

void process()
{
    int n;
    cin>>n;
    char ch=getchar();
    dl t;
    for (int i=1;i<=n;i++)
    {
        dl s;
        read(s);
        dl tmp;
        for (int i=max(0,(int)(t.size()-s.size()));i<t.size();i++) tmp.pb(t[i]);
        int h=same(s,tmp);
        for (int i=h;i<s.size();i++) t.pb(s[i]);
    }
    for (int i=0;i<t.size();i++) putchar(t[i]);
}

int main()
{
    //freopen("ss.inp","r",stdin);
    process();
    return 0;
}