#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void print(vector<int> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

const ll p = 1e9 + 7;

bool check(int idx, vector<int> &a)
{
    for (int i = 0; i<a.size(); i++) if (idx==a[i]) return true;
    return false;
}

void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> G(n+1);
    int a, b;
    for (int i = 0; i<n-1; i++)
    {
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    int k1, k2;
    cin>>k1;
    vector<int> Me(k1);
    for (int i = 0; i<k1; i++) cin>>Me[i];
    vector<bool> taken(n+1);
    for (int i = 0; i<k1; i++) taken[Me[i]] = true;
    
    cin>>k2;
    vector<int> Le(k2);
    for (int i = 0; i<k2; i++) cin>>Le[i];
    
    int start = Le[0];
    cout<<"B "<<start<<endl;
    cout.flush();
    
    cin>>start;
    if (taken[start]) {cout<<"C "<<start<<endl; cout.flush(); return;}
    
    vector<bool> visited(n+1);
    queue<int> kek;
    kek.push(start);
    visited[start] = true;
    while (1)
    {
        int t = kek.front();
        kek.pop();
        if (taken[t]) {start = t; break;}
        for (int i = 0; i<G[t].size(); i++) if (!visited[G[t][i]]) {visited[G[t][i]] = true; kek.push(G[t][i]);}
    }
    
    cout<<"A "<<start<<endl;
    cout.flush();
    int start1;
    cin>>start1;
    if (check(start1, Le)) {cout<<"C "<<start<<endl; cout.flush(); return;}
    else {cout<<"C "<<-1<<endl; cout.flush(); return;}
    
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);    

    int t;
    cin>>t;
    for (int i = 0; i<t; i++) solve();
    
    
}