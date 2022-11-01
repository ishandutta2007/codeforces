#include <bits/stdc++.h>

using namespace std;

vector<int> a;

int solve(vector<int> v,int e)
{
    if(v.empty()||e==-1) return 0;
    vector<bool> t(2,0);
    for(int id:v) t[(a[id]>>e)&1]=1;
    if(t[0]==0||t[1]==0) return solve(v,e-1);
    vector<int> b[2];
    for(int id:v) b[(a[id]>>e)&1].push_back(id);
    return (1<<e)+min(solve(b[0],e-1),solve(b[1],e-1));
}

int main()
{
    int n;
    scanf("%d",&n);
    a.resize(n);
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        v.push_back(i);
    }
    printf("%d\n",solve(v,29));
    return 0;
}