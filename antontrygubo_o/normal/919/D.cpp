#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<bool> visited;
vector<int> timein;
vector<int> timeout;

vector<int> topsort;
int dfstimer = 0;
bool cycle = false;

vector<vector<int>> letters;

void dfs(int v)

{
    if (!cycle)
    {
       //cout<<v<<endl;
        timein[v] = dfstimer;
        visited[v] = true;
        dfstimer++;
        for (int i = 0; i<G[v].size(); i++)
        {
            if ((visited[G[v][i]] == true)&&(timeout[G[v][i]]==0)) cycle = true;
        }
        
        for (int i = 0; i<G[v].size(); i++)
        {
            if (visited[G[v][i]] == false) dfs(G[v][i]);
        }
        timeout[v] = dfstimer;
        topsort.push_back(v);
        dfstimer++;
    }
}

int main()
{
int n, m;
cin>>n>>m;
for (int i = 0; i<n; i++)
{
    vector<int>temp;
    G.push_back(temp);
}

string s;
cin>>s;
int a, b;
for (int i = 0; i<m; i++)
{
    cin>>a>>b;
    if (a==b) {cout<<-1; return 0;}
    else G[a-1].push_back(b-1);
}

//cout<<G[5].size()<<endl<<endl;

for (int i = 0; i<n; i++) visited.push_back(false);
for (int i = 0; i<n; i++) timein.push_back(0);
for (int i = 0; i<n; i++) timeout.push_back(0);

for (int i = 0; i<n; i++)
if (visited[i]==false) dfs(i);
if (cycle==true) {cout<<-1; return 0;}

//for (int i = 0; i<n; i++) cout<<timeout[i]<<' '; 
for (int i = 0; i<n; i++)
{
    vector<int> temp;
    for (int j = 0; j<26; j++) temp.push_back(0);
    letters.push_back(temp);
}

int maxx = 0;

  for (int i = 0; i<n; i++)
  {
      int temp = topsort[i];
      
      for (int j = 0; j<G[temp].size(); j++)
      {
          for (int let = 0; let<26; let++)
          {
              letters[temp][let] = max(letters[temp][let], letters[G[temp][j]][let]);
          }
      }
      letters[temp][int(s[temp])-97]++;
      for (int j = 0; j<26; j++) maxx = max(maxx, letters[temp][j]);
  }

  

 cout<<maxx;   
}