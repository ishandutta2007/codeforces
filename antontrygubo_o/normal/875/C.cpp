#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<int>> G;

bool check = true;

set<int> appl;
set<int> stay;

void deal(vector<int> a, vector<int> b)
{
    int idx = 0;
    int a1 = a.size();
    int b1 = b.size();
    while (idx<a1&&idx<b1&&a[idx]==b[idx]) idx++;

    if (a1<=b1&&a1==idx) return;
    if (a1>b1&&idx==b1) {check = false; return;}
    if (a[idx]>b[idx]) {appl.insert(a[idx]); stay.insert(b[idx]);}
    else
    {
        G[b[idx]].push_back(a[idx]);
    }
    
}

vector<bool> used;

queue<int> q;

void bfs()
{
    while (!q.empty()) 
    {
	    int v = q.front();
	    q.pop();
	    for (size_t i=0; i<G[v].size(); ++i) 
	    {
		    int to = G[v][i];
		    if (!used[to]) 
		    {
			    used[to] = true;
			    q.push(to);
			    if (appl.find(v)!=appl.end()) appl.insert(to);
		    }
	    }
    }
}

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin>>n>>m;
    for (int i = 0; i<=m; i++) used.push_back(0);
    vector<vector<int>> a;
    for (int i = 0; i<n; i++) 
    {
        int temp;
        cin>>temp;
        vector<int> kek(temp);
        for (int j = 0; j<temp; j++) cin>>kek[j];
        a.push_back(kek);
    }
    for (int i = 0; i<=m; i++)
    {
        vector<int> temp;
        G.push_back(temp);
    }
    for (int i = 0; i<n-1; i++) deal(a[i], a[i+1]);
    
    for (auto it = appl.begin(); it!=appl.end(); it++) {q.push(*it); used[*it] = true;}
    bfs();
    vector<int> res(200000);
    auto it = set_intersection(appl.begin(), appl.end(), stay.begin(), stay.end(), res.begin());
    res.resize(it-res.begin());
    if (res.size()!=0||!check) {cout<<"No"; return 0;}
    
    cout<<"Yes"<<endl;
    cout<<appl.size()<<endl;
    for (auto it = appl.begin(); it!=appl.end(); it++) cout<<*it<<' ';

    

}