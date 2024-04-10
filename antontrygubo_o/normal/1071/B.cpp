#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 1e9 + 7;

char a[2000][2000];
int need[2000][2000];
bool visited[2000][2000];

int main()
{
    ios_base::sync_with_stdio(0);
    int n, k;
    cin>>n>>k;
    if (k>2*n-1) k = 2*n-1;
    string s;
    for (int i = 0; i<n; i++) 
    {
        cin>>s;
        for (int j = 0; j<n; j++) a[i][j] = s[j];
    }
    if (k==0) {cout<<a[0][0]; a[0][0] = 'a';}
    else 
    {
        cout<<'a';
        if (a[0][0]!='a')
        {
            k--; a[0][0] = 'a';
        }
    }
    
    
    for (int i = 0; i<n; i++)
    for (int j = 0; j<n; j++) {need[i][j] = 1000000; visited[i][j] = 0;}
    need[0][0] = 0;
    for (int i = 0; i<n; i++)
    for (int j = 0; j<n; j++)
    {
        if (i>0)
        need[i][j] = min(need[i][j], need[i-1][j]);
        if (j>0) 
        need[i][j] = min(need[i][j], need[i][j-1]);
        if (a[i][j]!='a') need[i][j]++;
    }
    
    int maxx = 0;
    for (int i = 0; i<n; i++)
    for (int j = 0; j<n; j++)
    if (need[i][j]<=k) maxx = max(maxx, i+j);
    if (maxx == 2*n-2)
    {
        for (int i = 0; i<2*n-2; i++) cout<<'a';
        return 0;
    }

    vector<pair<int, int> > cur;
    for (int i = 0; i<maxx; i++) cout<<'a';
    for (int i = 0; i<n; i++)
    for (int j = 0; j<n; j++)
    {
        if (i+j==maxx&&need[i][j]==k) {a[i][j] = 'a'; cur.push_back(make_pair(i, j));}
    }
    
   // cout<<maxx<<' '<<need[0][0]<<endl;
    for (int t = maxx+1; t<2*n-1; t++)
    {
        vector<pair<int, int> > temp;
        char x = 'z';
        for (int i = 0; i<cur.size(); i++) x = min(x, a[cur[i].first][cur[i].second]);
        if (t!=maxx+1) cout<<x;
        for (int i = 0; i<cur.size(); i++)
        {
            if (visited[cur[i].first][cur[i].second] == true) continue;
            if (a[cur[i].first][cur[i].second]==x)
            {
                if (cur[i].first<n-1) temp.push_back(make_pair(cur[i].first+1, cur[i].second));
                if (cur[i].second<n-1) temp.push_back(make_pair(cur[i].first, cur[i].second+1));                
            }
            visited[cur[i].first][cur[i].second] = true;
        }
        cur = temp;
    }
    cout<<a[n-1][n-1];
    
}