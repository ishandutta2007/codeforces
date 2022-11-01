#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<set<int>> row(n+1,{0,m+1});
    vector<set<int>> col(m+1,{0,n+1});
    for(int i=0;i<k;i++)
    {
        int a,b;
        cin >> a >> b;
        row[a].insert(b);
        col[b].insert(a);
    }
    auto prv=[](set<int> &s,int x)->int
    {
        auto it=s.lower_bound(x);
        it--;
        return (*it);
    };
    auto nxt=[](set<int> &s,int x)->int
    {
        return (*s.upper_bound(x));
    };
    ll cnt=1;
    int a=1,b=1;
    int l=0,r=m+1,u=0,d=n+1;
    bool one=1;
    while(1)
    {
        //right
        int to=min(r,nxt(row[a],b));
        if(to<=b+1&&one==0) break;
        if(to>b+1)
        {
            cnt+=(to-b-1);
            b=to-1;
            r=to;
        }
        u=a;
        //down
        to=min(d,nxt(col[b],a));
        if(to<=a+1) break;
        cnt+=(to-a-1);
        a=to-1;
        d=to;
        r=b;
        //left
        to=max(l,prv(row[a],b));
        if(to>=b-1) break;
        cnt+=(b-to-1);
        b=to+1;
        l=to;
        d=a;
        //up
        to=max(u,prv(col[b],a));
        if(to>=a-1) break;
        cnt+=(a-to-1);
        a=to+1;
        u=to;
        l=b;
        one=0;
    }
    if((ll)n*m-k==cnt) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}