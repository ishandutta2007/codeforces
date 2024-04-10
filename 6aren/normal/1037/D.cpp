#include <bits/stdc++.h>
using namespace std;
map <int,int> edge[200005];
int n,s[200005];
int main()
{
    int i,j,a,b;
    cin >> n;
    for (i=1;i<n;i++)
    {
        cin >> a >> b;
        edge[a][b]=1;
        edge[b][a]=1;
    }
    for (i=1;i<=n;i++)
    {
        cin >> s[i];
    }
    //cout << edge[1][3];
    bool res=true;
    i=1;j=2;
    while (res==true)
    {
        if (edge[s[i]][s[j]]) j++;
        else i++;
        if (i>=j) res=false;
    }
    if (j==n+1 && s[1]==1) cout << "YES";
    else cout << "NO";
}