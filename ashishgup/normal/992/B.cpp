#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int l, r, x, y, ans=0;

vector<int> factorise(int k)
{
    vector<int> v;
    for(int i=2;i*i<=k;i++)
    {
        int cnt=0, store=1;
        while(k%i==0)
        {
            k/=i;
            store*=i;
            cnt++;
        }
        if(cnt)
            v.push_back(store);
    }
    if(k>1)
        v.push_back(k);
    return v;
}

int32_t main()
{
    IOS;
    cin>>l>>r>>x>>y;
    if(y%x!=0)
    {
        cout<<0;
        return 0;
    }
    vector<int> v=factorise(y/x);
    int n=v.size();
    set<pair<int, int> > answer;
    for(int i=0;i<(1<<n);i++)
    {   
        int cur=y;
        for(int j=0;j<n;j++)
        {
            if((i>>j)&1)
                cur/=v[j];
        }
        if(cur>=l && cur<=r && (x*y/cur)<=r && (x*y/cur)>=l)
            answer.insert({cur, x*y/cur});
    }
    cout<<answer.size();
    return 0;
}