#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll N = 10000009;

int n;
string s;
vector<vector<ll>> Hash;

void init()
{
    for (int i = 0; i<26; i++)
    {
        vector<ll> temp;
        for (int j = 0; j<=n; j++) temp.push_back(0);
        Hash.push_back(temp);
    }
}

void hasher()
{
    for (int j = n-1; j>=0; j--)
    {
        for (int i = 0; i<26; i++) Hash[i][j] = (31*Hash[i][j+1])%N;
        Hash[s[j]-'a'][j]++;
    }
}

vector<int> degs;

void initdegs()
{
    degs.push_back(1);
    for (int i = 0; i<n; i++) degs.push_back((31*degs[i])%N);
}

void print(multiset<pair<ll, int>> res)
{
    for (auto start = res.begin(); start!=res.end(); start++)
    {
        cout<<(*start).first<<' '<<(*start).second<<endl;
    }
}

multiset<ll> res(int x, int len)
{
    multiset<ll> result;
    for (int i = 0; i<26; i++)
    {
        ll c = (Hash[i][x]-(Hash[i][x+len]*degs[len]))%N;
        while (c<0) c+=N;
        result.insert(c);
    }
    return result;
}

bool compare(multiset<pair<ll, int>> res1, multiset<pair<ll, int>> res2)
{
    bool check = true;
    auto r1 = res1.begin();
    auto r2 = res2.begin();
    for (int i = 0; i<26; i++)
    {
        if ((*r1).first!=(*r2).first) check = false;
        r1++;
        r2++;
    }
    return check;
}
/*
bool check(int x, int y, int len)
{
    return compare(res(x, len), res(y, len));
}*/


int main() 
{
    ios_base::sync_with_stdio(false);
    int m;
    cin>>n>>m;
    cin>>s;
    int x, y, len;
    init();
    hasher();
    initdegs();
    for (int i = 0; i<m; i++)
    {
        cin>>x>>y>>len;
        x--;
        y--;
        //cout<<i<<' '<<x<<' '<<y<<' '<<len<<endl;
        //res(x, len);
        //print(res(x, len));
        if (res(x, len)==res(y, len)) cout<<"YES";
        else cout<<"NO";
        cout<<endl;

    }
    
}