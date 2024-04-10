#include<bits/stdc++.h>
 
#define ll long long 

using namespace std;

map<ll, vector<ll>> cost;
set<ll> numbers;

 
int main()
{
    ios_base::sync_with_stdio(false);
    ll n; ll m;
    ll a, x;
    cin>>n;
    for (int i = 0; i<n; i++)
    {
        cin>>a>>x;
        numbers.insert(a);
        vector<ll> temp;
        temp.push_back(x);
        cost[a] = temp;
    }
    
    cin>>m;
    for (int i = 0; i<m; i++)
    {
        cin>>a>>x;
        if (numbers.find(a)==numbers.end())
        {
            numbers.insert(a);
            vector<ll> temp;
            temp.push_back(x);
            cost[a] = temp;
        }
        else
        {
            cost[a].push_back(x);
        }
    }

    ll summa = 0;

    for (auto t = numbers.begin(); t!=numbers.end(); t++)
    {
        if (cost[*t].size()==1) summa+=(cost[*t][0]);
        else summa+=max(cost[*t][0], cost[*t][1]);
    }
    cout<<summa;
}