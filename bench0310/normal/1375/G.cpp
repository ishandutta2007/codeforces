#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> v(n+1);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> c(n+1,0);
    c[1]=1;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(int to:v[a])
        {
            if(c[to]!=0) continue;
            c[to]=3-c[a];
            q.push(to);
        }
    }
    vector<int> x(3,0);
    for(int i=1;i<=n;i++) x[c[i]]++;
    cout << min(x[1],x[2])-1 << "\n";
    return 0;
}