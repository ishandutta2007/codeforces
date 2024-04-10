#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd (ll a, ll b, ll & x, ll & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

pair<int, int> solve(ll n, ll m, ll x, ll y, ll vx, ll vy)
{
    if (vx==0)
    {
        if (x==0)
        {
            if (vy==-1) return(make_pair(0, 0));
            else return(make_pair(0, m));
        }
        else if (x==n)
        {
            if (vy==-1) return(make_pair(n, 0));
            else return(make_pair(n, m));
        }
        else return (make_pair(-1, -1));
    }
    
    if (vy==0)
    {
        if (y==0)
        {
            if (vx==-1) return(make_pair(0, 0));
            else return(make_pair(n, 0));
        }
        else if (y==m)
        {
            if (vx==-1) return(make_pair(0, m));
            else return(make_pair(n, m));
        }
        else return (make_pair(-1, -1));
    }    
    if ((vx==vy)&&((x-y)%__gcd(m, n)!=0)) return(make_pair(-1, -1));
    if ((vx!=vy)&&((x+y)%__gcd(m, n)!=0)) return(make_pair(-1, -1));
    if (vx==-1)
    {
        pair<int, int> res = solve(n, m, n-x, y, 1, vy);
        return(make_pair(n-res.first, res.second));
    }
    
    if (vy==-1)
    {
        pair<int, int> res = solve(n, m, x, m-y, vx, 1);
        return(make_pair(res.first, m-res.second));
    }

    ll k = n-x+y;
    ll n1 = n;
    ll m1 = m;
    ll g = __gcd(m, n);
    k/=g;
    n1/=g;
    m1/=g;
    ll x1;
    ll y1;
    gcd(n1, m1, x1, y1);
    //cout<<n1<<' '<<m1<<' '<<x1<<' '<<y1<<endl;
    if (x1<0) x1+=m;
    x1 = x1%m;
    ll t = -k*x1;
    t%=m1;
    //cout<<t<<endl;
    while (t<0) t+=m1;
    //cout<<x<<' '<<y<<endl;
    ll n2 = n*(t+1);
    ll m2 = y-x+n*(t+1);

    n2%=(2*n);
    m2%=(2*m);
    //cout<<vx<<' '<<vy<<' '<<x<<' '<<y<<' '<<n2<<' '<<m2<<endl;
    return(make_pair(int(n2), int(m2)));
}

void write(ll n, ll m, ll x, ll y, ll vx, ll vy)
{
    pair<int, int> res = solve(n, m, x, y, vx, vy);
    if (res.first!=-1)
    {
        cout<<res.first<<' '<<res.second;
    }
    else cout<<-1;
}
int main()
{
    ll n, m, x, y, vx, vy;
    cin>>n>>m>>x>>y>>vx>>vy;
    write(n, m, x, y, vx, vy);
    
    
}