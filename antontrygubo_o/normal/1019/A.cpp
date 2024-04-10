#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n, m;

vector<int> points;

vector<vector<ll>> prices;

multiset<ll> my;

ll solve(int t)
{
    int addtofirst = 0;
    ll countprice = 0;
    for (int i = 1; i<m; i++)
    {
        if (prices[i].size()>t)
        {
            addtofirst+=(prices[i].size()-t);
            for (int j = 0; j+t<prices[i].size(); j++) countprice+=prices[i][j];
        }
    }
    if (prices[0].size()+addtofirst<=t)
    {
        my.clear();
        for (int i = 1; i<m; i++)
        {
            for (int j = max(0, int(prices[i].size())-t); j<prices[i].size(); j++) my.insert(prices[i][j]);
        }
        auto kek = my.begin();
        for (int i = 0; i<t+1-prices[0].size()-addtofirst; i++)
        {
            countprice+=*kek;
            kek++;
        }
    }
    return countprice;
}

int main() 
{
    cin>>n>>m;
    for (int i = 0; i<m; i++)
    {
        vector<ll> temp;
        prices.push_back(temp);
    }
    int a;
    ll b;
    for (int i = 0; i<m; i++) points.push_back(0);
    for (int i = 0; i<n; i++) {cin>>a>>b; points[a-1]++; prices[a-1].push_back(b);}
    for (int i = 0; i<m; i++) sort(prices[i].begin(), prices[i].end());
    
    ll best = 1000000000000000;
    for (int i = 0; i<=n-1; i++)
    {
        best = min(best, solve(i));
    }
    
    cout<<best;
    
    
    
}