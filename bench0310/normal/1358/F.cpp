#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n,0);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<ll> b(n,0);
    for(int i=0;i<n;i++) cin >> b[i];
    auto rev=[&](vector<ll> v)->vector<ll>
    {
        reverse(v.begin(),v.end());
        return v;
    };
    auto inc=[&](vector<ll> v)->bool
    {
        for(int i=0;i+1<n;i++) if(v[i]>=v[i+1]) return 0;
        return 1;
    };
    auto rollback=[&](vector<ll> v)->vector<ll>
    {
        for(int i=n-1;i>=1;i--) v[i]-=v[i-1];
        return v;
    };
    const int lim=200000;
    bool ok=0;
    ll m=0;
    string res;
    if(n==1)
    {
        if(a[0]==b[0]) ok=1;
    }
    else if(n==2)
    {
        vector<ll> t;
        bool e=0;
        if(a[0]>a[1])
        {
            e=1;
            a=rev(a);
        }
        while(1)
        {
            if(b==a||rev(b)==a)
            {
                ok=1;
                if(rev(b)==a) t.push_back(-1);
                break;
            }
            if(b[0]>b[1])
            {
                b=rev(b);
                t.push_back(-1);
            }
            if(b[0]==0) break;
            if(a[0]==b[0]&&b[1]>a[1]&&((b[1]-a[1])%b[0])==0)
            {
                ll x=(b[1]-a[1])/b[0];
                t.push_back(x);
                m+=x;
                ok=1;
                break;
            }
            t.push_back(b[1]/b[0]);
            m+=(b[1]/b[0]);
            b[1]%=b[0];
        }
        if(e) t.push_back(-1);
        if(ok&&m<=lim)
        {
            for(ll c:t)
            {
                if(c==-1) res+="R";
                else res+=string(c,'P');
            }
        }
    }
    else
    {
        while(1)
        {
            if(b==a||rev(b)==a)
            {
                ok=1;
                if(rev(b)==a) res+="R";
                break;
            }
            if(inc(b)||inc(rev(b)))
            {
                if(inc(b)==0)
                {
                    res+="R";
                    b=rev(b);
                }
                res+="P";
                m++;
                b=rollback(b);
            }
            else break;
        }
    }
    reverse(res.begin(),res.end());
    if(ok)
    {
        if(m<=lim)
        {
            cout << "SMALL\n";
            cout << res.size() << "\n";
            cout << res << "\n";
        }
        else
        {
            cout << "BIG\n";
            cout << m << "\n";
        }
    }
    else cout << "IMPOSSIBLE\n";
    return 0;
}