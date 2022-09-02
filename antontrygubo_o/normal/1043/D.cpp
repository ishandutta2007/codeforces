#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 998244353;


int main()
{
    ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    vector<vector<int>> a(m, vector<int> (n));
    for (int i = 0; i<m; i++)
    for (int j = 0; j<n; j++) {cin>>a[i][j]; a[i][j]--;}
    ll answer = n;
    vector<set<int> > my(n);
    for (int i = 0; i<m; i++) 
    for (int j = 0; j<n; j++)
    {
        if (j!=n-1) my[a[i][j]].insert(a[i][j+1]);
        else my[a[i][j]].insert(-1);
    }
    
    vector<bool> check(n-1, 0);
    for (int i = 0; i<n-1; i++) if (my[a[0][i]].size()==1) {check[i] = 1; }
    
    //for (int i = 0; i<n-1; i++) cout<<check[i]<<' ';
    //cout<<endl;
    
    ll current = 0;
    for (int i = 0; i<n-1; i++)
    {
        if (check[i]==1) current++;
        else {answer+=(current*(current+1))/2; current = 0;}
    }
    answer+=(current*(current+1))/2;
    cout<<answer;
    
    
}