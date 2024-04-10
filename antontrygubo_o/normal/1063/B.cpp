#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define mp make_pair
int n, m, r, c, x, y;


queue<pair<int, int>> a;

vector<vector<int>> table(2000, vector<int>(2000));
vector<vector<pair<int, int>>> minrl(2000, vector<pair<int, int>>(2000));
vector<vector<int>> visited(2000, vector<int>(2000));

void clean(pair<int, int> g)
{
    int r1 = g.first;
    int c1 = g.second;
    int rd = r1-1;
    while (rd>=0&&visited[rd][c1]==0&&table[rd][c1]==0) {minrl[rd][c1] = minrl[rd+1][c1]; a.push(mp(rd, c1)); visited[rd][c1] = 1; rd--;}
    int ru = r1+1;
    while (ru<n&&visited[ru][c1]==0&&table[ru][c1]==0) {minrl[ru][c1] = minrl[ru-1][c1]; a.push(mp(ru, c1)); visited[ru][c1] = 1; ru++;}
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>r>>c>>x>>y;
    r--;
    c--;
    minrl[r][c] = mp(0, 0);
    visited[r][c] = 1;
    char temp;
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<m; j++)
        {cin>>temp; if (temp=='.') table[i][j] = 0;
        else table[i][j] = 1;}
    }
    /*for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<m; j++) cout<<table[i][j];
        cout<<endl;
    }*/
    a.push (mp(r, c));
    int counter = 0;
    clean(mp(r, c));
    while (!a.empty())
    {
        auto tem = a.front();
        a.pop();
        int rr = tem.first;
        int cc = tem.second;
        if (cc>0&&table[rr][cc-1]==0&&visited[rr][cc-1]==0) 
        {a.push(mp(rr, cc-1)); visited[rr][cc-1] = 1; minrl[rr][cc-1] = minrl[rr][cc]; minrl[rr][cc-1].first++; clean(mp(rr, cc-1)); }
        if (cc<m-1&&table[rr][cc+1]==0&&visited[rr][cc+1]==0) 
        {a.push(mp(rr, cc+1)); visited[rr][cc+1] = 1; minrl[rr][cc+1] = minrl[rr][cc]; minrl[rr][cc+1].second++; clean(mp(rr, cc+1));}
    }
    for (int i = 0; i<n; i++)
    for (int j = 0; j<m; j++)
    {
        if (visited[i][j]==1)
        {
            if (minrl[i][j].first<=x&&minrl[i][j].second<=y) counter++;
        }
    }
    cout<<counter;
}