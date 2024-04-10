#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<vector<int>> G1;

vector<bool> visited;
vector<bool> govno;
vector<bool> govno2;
vector<bool> notbad;


int leastidx;
int bestcompsize = 100000000;
int n;
int countt = 0;


int dfsfind(int v)
{
    visited[v] = true;
    for (int i = 0; i<G[v].size(); i++)
    {
        if (!visited[G[v][i]]) return(dfsfind(G[v][i]));
    }
    return v;
}
//make count = 0;
int dfscount(int v)
{
    govno[v] = true;
    countt++;
    for (int i = 0; i<G[v].size(); i++)
    {
        if (!govno[G[v][i]]) dfscount(G[v][i]);
    }
    return countt;
}

void dfsgovno2(int v)
{
    govno2[v] = 1;
    for (int i = 0; i<G1[v].size(); i++)
    {
        if (!govno2[G1[v][i]]) dfsgovno2(G1[v][i]);
    }
}

void dfscout(int v)
{
    cout<<v+1<<' ';
    notbad[v] = true;
    for (int i = 0; i<G[v].size(); i++)
    {
        if (!notbad[G[v][i]]) dfscout(G[v][i]);
    }
}


int main()
{
    int m, h;
    cin>>n>>m>>h;
    int c1, c2;
    for (int i = 0; i<n; i++)
    {
        vector<int> temp; G.push_back(temp);
    }
    
    for (int i = 0; i<n; i++)
    {
        vector<int> temp; G1.push_back(temp);
    }
    
    for (int i = 0; i<n; i++) visited.push_back(0);
    for (int i = 0; i<n; i++) govno.push_back(0);  
    for (int i = 0; i<n; i++) govno2.push_back(0); 
    for (int i = 0; i<n; i++) notbad.push_back(0); 
    
    int a[n];
    for (int i = 0; i<n; i++) cin>>a[i];
    
    for (int i = 0; i<m; i++)
    {
        cin>>c1>>c2;
        c1--;
        c2--;
        if ((a[c2]+1)%h==a[c1]) {G[c2].push_back(c1); G1[c1].push_back(c2);}
        if ((a[c1]+1)%h==a[c2]) {G[c1].push_back(c2); G1[c2].push_back(c1);}
    }
    
    //cout<<"GRAPH"<<endl;
    //for (int i = 0; i<n; i++)
    //{
    //    cout<<"for i = "<<i<<" : ";for (int j = 0; j<G[i].size(); j++) cout<<G[i][j]<<' ';
    //    cout<<endl;
   // }
    //cout<<"GRAPH"<<endl;
   // cout<<"GRAPH1"<<endl;
   // for (int i = 0; i<n; i++)
   // {
   //     cout<<"for i = "<<i<<" : ";for (int j = 0; j<G1[i].size(); j++) cout<<G1[i][j]<<' ';
   //     cout<<endl;
   // }
    //cout<<"GRAPH1"<<endl;
    
    //cout<<dfscount(1)<<endl<<endl;
    
    for (int i = 0; i<n; i++)
    {
        if (!govno2[i])
        {
    //        cout<<i<<' ';
            int t = dfsfind(i);
     //       cout<<t<<' ';
            countt = 0;
            int k = dfscount(t);
    //        cout<<k<<endl;
            if (k<bestcompsize) {leastidx = t; bestcompsize = k;}
            dfsgovno2(t);
        }
    }
    //cout<<endl;
    
    //for (int i = 0; i<n; i++) cout<<govno2[i]<<' '; cout<<endl;
    //dfsgovno2(1);
    //for (int i = 0; i<n; i++) cout<<govno2[i]<<' '; cout<<endl;
    //cout<<endl;
    cout<<bestcompsize<<endl;
    dfscout(leastidx);
    
}