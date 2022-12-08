#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
int ne[sz][26], q=1;
vector <int> sp[sz];
void dfs(int v)
{
    for(int a=0; a<26; a++)
    {
        int u=ne[v][a];
        if(u!=-1)
        {
            dfs(u);
            if(sp[u][0]!=0) sp[v].push_back(1);
            for(int b=0; b<sp[u].size(); b++) sp[v].push_back(sp[u][b]+1);
            if(sp[u][0]!=0) sp[v].pop_back();
        }
    }
    sort(sp[v].begin(), sp[v].end());
}
int main()
{
    int n;
    cin>>n;
    string s[n];
    for(int a=0; a<n; a++) cin>>s[a];
    for(int a=0; a<26; a++) ne[0][a]=-1;
    for(int a=0; a<n; a++)
    {
        int cu=0;
        for(int b=0; b<s[a].size(); b++)
        {
            int sy=s[a][b]-'a';
            if(ne[cu][sy]==-1)
            {
                ne[cu][sy]=q;
                for(int c=0; c<26; c++) ne[q][c]=-1;
                q++;
            }
            cu=ne[cu][sy];
        }
        sp[cu].push_back(0);
    }
    dfs(0);
    int an=0;
    for(int a=0; a<sp[0].size(); a++) an+=sp[0][a];
    cout<<an;
}