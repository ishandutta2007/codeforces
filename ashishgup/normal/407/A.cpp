#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int a, b;
vector<pair<int, int> > v[2];

int f(int k)
{
    return k*k;
}

void work(int i, int k)
{
    for(int dx=-k;dx<=k;dx++)
    {
        for(int dy=-k;dy<=k;dy++)
        {
            if(dx==0 || dy==0)
                continue;
            if(f(dx) + f(dy) == f(k))
                v[i].push_back({dx, dy});
        }
    }
}

int32_t main()
{
    IOS;
    cin>>a>>b;
    work(0, a);
    work(1, b);
    for(auto p:v[0])
    {
        for(auto q:v[1])
        {
            if(p.first==q.first || p.second==q.second)
                continue;
            if(f(p.first-q.first) + f(p.second-q.second) != f(a) + f(b))
                continue;
            cout<<"YES"<<endl;
            cout<<"0 0"<<endl;
            cout<<p.first<<" "<<p.second<<endl;
            cout<<q.first<<" "<<q.second<<endl;
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}