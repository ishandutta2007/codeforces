#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;

int n;
int a[N], b[N], p[N];
set<int> s;
vector<int> v;

void work()
{
    int cnta=0, cntb=0, idx=0;
    for(int i=1;i<=n;i++)
    {
        if(p[i]!=-1)
        {
            cnta+=(p[i]!=a[i]);
            cntb+=(p[i]!=b[i]);
        }
        else
        {
            cnta+=(v[idx]!=a[i]);
            cntb+=(v[idx]!=b[i]);
            idx++;
        }
    }
    if(cnta==1 && cntb==1)
    {
        idx=0;
        for(int i=1;i<=n;i++)
        {
            if(p[i]!=-1)
                cout<<p[i]<<" ";
            else
                cout<<v[idx++]<<" ";
        }
        exit(0);
    }
}

int32_t main()
{
    IOS;
    memset(p, -1, sizeof(p));
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        if(a[i]==b[i])
        {
            p[i]=a[i];
            s.insert(a[i]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(s.find(i)==s.end())
            v.push_back(i);
    }
    do
    {
        work();
    }while(next_permutation(v.begin(), v.end()));
    return 0;
}