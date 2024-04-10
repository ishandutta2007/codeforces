#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N];
map<int, int> m;
priority_queue <pair<int, int> , vector<pair<int, int> > > pq;
vector<vector<int> > ans;

pair<int, int> getnew()
{
    pair<int, int> p=pq.top();
    pq.pop();
    p.first--;
    return p;
}

int32_t main()
{ 
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        m[a[i]]++;
    }
    for(auto it:m)
    {
        pq.push(make_pair(it.second, it.first));
    }
    while(pq.size()>=3)
    {
        int ct=0;
        pair<int, int> p=getnew();
        pair<int, int> q=getnew();
        pair<int, int> r=getnew();
        vector<int> cur;
        cur.push_back(p.second);
        cur.push_back(q.second);
        cur.push_back(r.second);
        sort(cur.begin(), cur.end());
        reverse(cur.begin(), cur.end());
        ans.push_back(cur);
        if(p.first>=1)
        {
            pq.push(p);
        }
        if(q.first>=1)
        {
            pq.push(q);
        }
        if(r.first>=1)
        {
            pq.push(r);
        }
    }
    cout<<ans.size()<<endl;
    for(auto it:ans)
    {
        for(auto j:it)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}