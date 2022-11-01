#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> v(n+1,0);
    vector<bool> gift(n+1,0);
    vector<int> a,b;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&v[i]);
        if(v[i]==0) a.push_back(i);
        gift[v[i]]=1;
    }
    for(int i=1;i<=n;i++) if(gift[i]==0) b.push_back(i);
    for(int i=0;i<(int)a.size()-1;i++)
    {
        if(a[i]==b[i]||a[i+1]==b[i+1]) swap(b[i],b[i+1]);
    }
    for(int i=0;i<(int)a.size();i++) v[a[i]]=b[i];
    for(int i=1;i<=n;i++) printf("%d%c",v[i]," \n"[i==n]);
    return 0;
}