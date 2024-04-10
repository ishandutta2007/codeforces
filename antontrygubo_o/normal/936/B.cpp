#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;

vector<bool> en;

vector<int> visited;

vector<int> prev0;
vector<int> prev1;
vector<bool> dfsnow;

bool cycle = false;

int start;

void dfs (int s)
{
    dfsnow[s] = true;
    visited[s]++;
    for (int i = 0; i<G[s].size(); i++)
    {
        int ch = G[s][i];
        if ((prev0[ch]==-1)&&(prev1[s]!=-1)) prev0[ch] = s;
        if ((prev1[ch]==-1)&&(prev0[s]!=-1)) prev1[ch] = s;
        if ((visited[ch])&&(dfsnow[ch])) cycle = true;
        if (visited[ch]<2)
        {
            dfs(ch);
        }
    }
    dfsnow[s]=false;
    
}

int main()
{
int n, m;
cin>>n>>m;
for (int i = 0; i<n; i++)
{
    vector<int> temp; G.push_back(temp);
}

for (int i = 0; i<n; i++) en.push_back(true);
for (int i = 0; i<n; i++) visited.push_back(0);
for (int i = 0; i<n; i++) prev0.push_back(-1);
for (int i = 0; i<n; i++) prev1.push_back(-1);
for (int i = 0; i<n; i++) dfsnow.push_back(0);

for (int i = 0; i<n; i++)
{
    int k;
    cin>>k;
    if (k) en[i]=false;
    int tem;
    for (int j = 0; j<k; j++) {cin>>tem; G[i].push_back(tem-1);}
}

cin>>start;
start--;
prev0[start] = -2;
dfs(start);

int win = -1;
for (int i = 0; i<n; i++)
if ((en[i]==true)&&(prev1[i]!=-1)) win = i;

if (win==-1)
{
    if (cycle) cout<<"Draw";
    else cout<<"Lose";
    return 0;
}
cout<<"Win"<<endl;
bool state = 1;
vector<int> answer;
answer.push_back(win);
while ((state==1)||(win!=start))
{
    if (state==1) {win = prev1[win]; answer.push_back(win);}
    if (state==0) {win = prev0[win]; answer.push_back(win);}
    state = !state;
}
for (int i = answer.size()-1; i>=0; i--) cout<<answer[i]+1<<' ';

}