#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> p;

vector<int> places;

bool sortvec(int a, int b)
{
    return places[a]<places[b];
}
vector<vector<int>> G;

bool check = true;

int idx = 0;

queue<int> q;
vector<bool> used;
void bfs()
{
    q.push(0);
    used[0] = true;
    while (!q.empty()) 
    {
	    int v = q.front();
	    q.pop();
	    //cout<<idx<<' '<<v<<' '<<p[idx]<<endl;
	    if (v!=p[idx]) check = false;
	    idx++;
	    for (size_t i=0; i<G[v].size(); ++i) 
	    {
		    int to = G[v][i];
		    if (!used[to]) 
		    {
			    used[to] = true;
			    q.push (to);
		    }
		}
	}
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    for (int i = 0; i<n; i++) used.push_back(0);
    for (int i = 0; i<n; i++) 
    {
        vector<int> temp; G.push_back(temp);
    }
    int a, b;
    for (int i = 0; i<n-1; i++)
    {
        cin>>a>>b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    for (int i = 0; i<n; i++) {cin>>a; a--; p.push_back(a);}
    for (int i = 0; i<n; i++) places.push_back(0);
    for (int i = 0; i<n; i++) places[p[i]] = i;
    
    if (p[0]!=0) {cout<<"No"; return 0;}
    
    for (int i = 0; i<n; i++)
    {
        sort(G[i].begin(), G[i].end(), sortvec);
    }
    bfs();
    if (check) cout<<"Yes";
    else cout<<"No";
    
}