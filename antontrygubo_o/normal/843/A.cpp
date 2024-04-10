#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll N = 998244353;


vector<int> kek;



bool s(ll x, ll y)
{
    return kek[x]<kek[y];
}


vector<ll> parent;
vector<ll> rang;


void make_set (ll v) 
{
    parent[v] = v;
    rang[v] = 0;
}

ll find_set (int v) 
{
    if (v == parent[v])
    return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (ll a, ll b) 
{
    a = find_set (a);
    b = find_set (b);
    if (a != b) 
    {
        if (rang[a] < rang[b])
        swap (a, b);
        parent[b] = a;
        if (rang[a] == rang[b])
        ++rang[a];
    }
}



int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin>>n;
    for (int i = 0; i<n; i++) kek.push_back(0);
    for (int i = 0; i<n; i++) cin>>kek[i];
    vector<int> b;
    for (int i = 0; i<n; i++) b.push_back(i);
    sort(b.begin(), b.end(), s);
    map<ll, ll> mp;
    for (int i = 0; i<n; i++) mp[kek[b[i]]]=i;
    
    for (int i = 0; i<n; i++) {rang.push_back(-1); parent.push_back(-1);}
    
    ll counter = 0;
    
    for (int i = 0; i<n; i++)
    {
        if (parent[i]==-1)
        {
            if (mp[kek[i]]==i) {counter++; make_set(i);}
            else
            {
                int j = mp[kek[i]];
                swap(kek[b[i]], kek[b[j]]);
                swap(b[i], b[j]);
                if (parent[j]!=-1) {make_set(i); union_sets(i, j);}
                else
                {
                    counter++;
                    make_set(i); make_set(j); union_sets(i, j);
                }
            }
            
        }
        else
        {
            if (mp[kek[i]]==i) {}
            else
            {
                int j = mp[kek[i]];
                swap(kek[b[i]], kek[b[j]]);
                swap(b[i], b[j]);
                if (parent[j]!=-1) {union_sets(i, j);}
                else
                {
                    make_set(j); union_sets(i, j);
                }
                
            }
        }

    }
    
set<ll> lol;
for (int i = 0; i<n; i++) lol.insert(find_set(i));

map<ll, vector<int>> check;

for (auto it = lol.begin(); it!=lol.end(); it++)
{
    check[*it].clear();
}


for (int i = 0; i<n; i++) check[find_set(i)].push_back(b[i]);

cout<<lol.size()<<endl;

for (auto it = lol.begin(); it!=lol.end(); it++)
{
    cout<<check[*it].size()<<' '; for (int j = 0; j<check[*it].size(); j++) cout<<check[*it][j]+1<<' ';
    cout<<endl;
}
    
}