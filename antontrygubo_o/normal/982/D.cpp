#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> pre;
vector<int> counter;
set<pair<int, int>> quantity; 

void add(int a)
{
    pre[a] = a;
    counter[a] = 1;
    quantity.insert({1, a});
}

int root(int a)
{
    if (a==pre[a]) return a;
    else return root(pre[a]);
}

void unite (int a, int b)
{
    a = root(a);
    b = root(b);
    if (counter[a]<counter[b]) swap(a, b);
    pre[b] = a;
    int t = counter[a]+counter[b];
    quantity.erase({counter[a], a});
    quantity.erase({counter[b], b});
    quantity.insert({t, a});
    counter[a] = t;
    counter[b] = -1;
}


int checker()
{
   auto f1 = quantity.begin();
   auto f2 = quantity.end();
   f2--;
   if ((*f1).first!=(*f2).first) return 0;
   else return quantity.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    vector<pair<int, int>> day;
    int n;
    cin>>n;
    for (int i = 0; i<n; i++) pre.push_back(-1);
    for (int i = 0; i<n; i++) counter.push_back(-1);
    int temp;
    for (int i = 0; i<n; i++)
    {
        cin>>temp; day.push_back({temp, i});
    }
    
    sort(day.begin(), day.end());
    int maxloc = 0;
    int best = 0;
    for (int i = 0; i<n; i++)
    {
        int t = day[i].second;
        add(t);
        if (t>0&&pre[t-1]!=-1) unite(t, t-1);
        if (t<n-1&&pre[t+1]!=-1) unite(t, t+1);
        int c = checker();
        if (c>maxloc)
        {
            maxloc = c;
            best = day[i].first+1;
        }
       // cout<<i<<' '<<checker()<<endl;
    }
    cout<<best;
    
}