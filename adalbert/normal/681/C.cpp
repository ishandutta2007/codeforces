#include <bits/stdc++.h>;
#define fin freopen("next.in","r",stdin)
#define fout freopen("next.out","w",stdout)
using namespace std;
long long n,p,k,r,o,b[1000000],b1[5000000];
multiset<int> a;
string st[1000000],s[5000000];
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>st[i];
        if (st[i]!="removeMin") cin>>b[i];
    }

    for (int i=1;i<=n;i++)
    {
        if (st[i]=="insert") a.insert(b[i]); else
        if (st[i]=="removeMin")
        {
            if (a.empty())
            {
                    k++;
                    s[k]="insert";
                    b1[k]=1;
            } else a.erase(a.begin());
        } else
        if (st[i]=="getMin")
        {
            if (!a.empty())
            while (*a.begin()<b[i])
            {
                k++;
                s[k]="removeMin";
                if (a.empty()) break;
                a.erase(a.begin());
                if (a.empty()) break;
            }
            if ((*a.begin()!=b[i])||(a.empty()))
            {
                k++;
                    s[k]="insert";
                    b1[k]=b[i];
                a.insert(b[i]);
            }
        }
        k++;
        s[k]=st[i];
        b1[k]=b[i];
    }
cout<<k<<'\n';
for (int i=1;i<=k;i++)
{
    cout<<s[i];
    if (s[i]=="removeMin") cout<<'\n'; else cout<<' '<<b1[i]<<'\n';
}
}