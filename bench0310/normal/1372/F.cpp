#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    auto q=[&](int l,int r)->array<int,2>
    {
        cout << "? " << max(l,1) << " " << min(r,n) << "\n";
        cout.flush();
        int x,f;
        cin >> x;
        if(x==-1) exit(0);
        cin >> f;
        return {x,f};
    };
    vector<int> res(n+1,0);
    function<void(int,int)> go=[&](int l,int r)
    {
        if(l>r) return;
        auto [x,f]=q(l,r);
        int p=1;
        while(2*p<=f) p*=2;
        array<int,2> pos={0,0};
        for(int i=((l+p-1)/p)*p;i<=r;i+=p)
        {
            if(res[i]==0) res[i]=q(i,i)[0];
            if(res[i]==x)
            {
                if(pos[0]==0) pos[0]=i;
                else pos[1]=i;
            }
        }
        if(pos[1]==0)
        {
            auto [ax,af]=q(pos[0]-p+1,pos[0]);
            auto [bx,bf]=q(pos[0],pos[0]+p-1);
            int one=((ax==x)?af:f-bf+1);
            int two=f-one+1;
            for(int i=pos[0]-one+1;i<=pos[0]+two-1;i++) res[i]=x;
            go(l,pos[0]-one);
            go(pos[0]+two,r);
        }
        else
        {
            auto [bx,bf]=q(pos[0],pos[1]+p-1);
            int two=bf-p;
            int one=f-two-p+1;
            for(int i=pos[0]-one+1;i<=pos[1]+two-1;i++) res[i]=x;
            go(l,pos[0]-one);
            go(pos[1]+two,r);
        }
    };
    go(1,n);
    cout << "! ";
    for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    cout.flush();
    return 0;
}