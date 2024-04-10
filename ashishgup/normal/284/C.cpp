#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n=1, q;
double sum=0;
int a[N], bit[N];

void update(int idx, int val)
{
    while(idx<=N)
    {
        bit[idx]+=val;
        idx+=(idx&(-idx));
    }
}

int pref(int idx)
{
    int ans=0;
    while(idx>0)
    {
        ans+=bit[idx];
        idx-=(idx&(-idx));
    }
    return ans;
}

int32_t main()
{
    IOS;
    cin>>q;
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int x, a;
            cin>>a>>x;
            sum+=x*a;
            update(1, +x);
            update(a+1, -x);
        }
        else if(type==2)
        {
            int k;
            cin>>k;
            sum+=k;
            n++;
            update(n, k);
            update(n+1, -k);       
        }
        else
        {
            int store=pref(n);
            sum-=store;
            update(n, -store);
            update(n+1, +store);
            n--;
        }
        double ans=sum/n;
        cout<<fixed<<setprecision(12)<<ans<<endl;
    }
    return 0;
}