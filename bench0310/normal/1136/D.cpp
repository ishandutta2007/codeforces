#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> p(n);
    for(int i=0;i<n;i++) scanf("%d",&p[i]);
    int player=p[n-1];
    vector<int> friends[n+1];
    vector<bool> playerFriends(n+1,0);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        if(b==player) playerFriends[a]=1;
        else friends[b].push_back(a);
    }
    int res=0;
    int len=0;
    vector<int> v(n+1,0);
    for(int i=n-2;i>=0;i--)
    {
        if(playerFriends[p[i]]&&v[p[i]]==len) res++;
        else
        {
            len++;
            for(int j=0;j<(int)friends[p[i]].size();j++) v[friends[p[i]][j]]++;
        }
    }
    cout << res << endl;
    return 0;
}