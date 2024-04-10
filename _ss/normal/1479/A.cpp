#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N=1e5+10;

int val[N],n;

int ask(int x)
{
    if (x==0 || x>n) return 1e9;
    if (val[x]) return val[x];
    cout<<"? "<<x<<endl;
    int res;
    cin>>res;
    val[x]=res;
    return res;
}

bool check(int x)
{
    return (ask(x)<min(ask(x-1),ask(x+1)));
}

int main()
{
    //freopen("ss.inp","r",stdin);
    cin>>n;
    int l=1,r=n;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (check(mid))
        {
            cout<<"! "<<mid<<endl;
            return 0;
        }
        if (l<=mid-1 && ask(mid-1)<ask(mid)) r=mid-1;
        else l=mid+1;
    }
    return 0;
}