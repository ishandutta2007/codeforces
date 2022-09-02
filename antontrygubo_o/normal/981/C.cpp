#include<bits/stdc++.h>
 
#define ll long long 

using namespace std;

vector<vector<int>> G;
 
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for (int i = 0; i<n; i++) 
    {
        vector<int> temp;
        G.push_back(temp);
    }
    int c, b;
    for (int i = 0; i<n-1; i++)
    {
        cin>>c>>b;
        c--;
        b--;
        G[c].push_back(b);
        G[b].push_back(c);
    }
    int a[n+1] = {0};
    for (int i = 0; i<n; i++)
    a[G[i].size()]++;
    if (a[1]+a[2]<n-1) {cout<<"No"; return 0;}
    cout<<"Yes"<<endl;
    vector<int> ones;
    for (int i = 0; i<n; i++)
    {
        if (G[i].size()==1) ones.push_back(i);
    }
    if (a[1]+a[2]==n)
    {
        cout<<1<<endl;
        cout<<ones[0]+1<<' '<<ones[1]+1; return 0;
    }
    int i = 0;
    while (G[i].size()<3) i++;
    cout<<ones.size()<<endl;
    for (int j = 0; j<ones.size(); j++)
    {
        cout<<i+1<<' '<<ones[j]+1<<endl;
    }
    
}