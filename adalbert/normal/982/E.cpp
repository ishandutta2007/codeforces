#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#pragma GCC optimize ("O2")
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int gcd (int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

pair<int,int> getcor(int n, int m, int x, int y, int vx, int vy)
{
    if (vx>0)
    {
        x=n-x;
    }
    if (vy>0)
    {
        y=m-y;
    }

    m=-m;
    x=y-x;

    if (x==0)
    {
        return(m_p(0,0));
    } else
    {
        int k1,k2;
        int c=gcd(n,m,k1,k2);
        if (x%c!=0)
        {
            return(m_p(-1,-1));
        }

        k1*=x/c;
        k2*=x/c;


        int p1=m/c;
        int p2=n/c;

        p1*=100;
        p2*=100;

        while (k1<0 || k2<0)
        {
            if (k1<0)
            {
                if (p1<0)
                {
                    k1-=p1;
                    k2+=p2;
                } else
                {
                    k1+=p1;
                    k2-=p2;
                }
            } else
            {
                if (p2>0)
                {
                    k1-=p1;
                    k2+=p2;
                } else
                {
                    k1+=p1;
                    k2-=p2;
                }
            }
        }

        while (k1-p1>=0 && k2+p2>=0 && p1>=0 && p2<=0)
        {
            k1-=p1;
            k2+=p2;
        }
        while (k1+p1>=0 && k2-p2>=0 && p1<=0 && p2>=0)
        {
            k1+=p1;
            k2-=p2;
        }

        p1/=100;
        p2/=100;

        while (k1-p1>=0 && k2+p2>=0 && p1>=0 && p2<=0)
        {
            k1-=p1;
            k2+=p2;
        }
        while (k1+p1>=0 && k2-p2>=0 && p1<=0 && p2>=0)
        {
            k1+=p1;
            k2-=p2;
        }

        return(m_p(k1,k2));
    }
}

signed main()
{
    int n,m,x,y,vx,vy;
    cin>>n>>m>>x>>y>>vx>>vy;
    int sx=x;
    int sy=y;

    if (vx==0)
    {
        if (x==0 || x==n)
        {
            if (vy<0)
                cout<<x<<' '<<0; else
                cout<<x<<' '<<m;
        } else
        cout<<-1;
    } else
    if (vy==0)
    {
        if (y==0 || y==m)
        {
            if (vx<0)
                cout<<0<<' '<<y; else
                cout<<n<<' '<<y;
        } else
        cout<<-1;
    } else
    {

        pair<int,int> p=getcor(n,m,x,y,vx,vy);
        if (p.fir==-1)
        {
            cout<<-1;
            return(0);
        }
        if (vx==1)
        {
            if (p.fir%2==0)
                cout<<n<<' '; else
                cout<<0<<' ';
        } else
        {
            if (p.fir%2==0)
                cout<<0<<' '; else
                cout<<n<<' ';
        }
        if (vy==1)
        {
            if (p.sec%2==0)
                cout<<m<<' '; else
                cout<<0<<' ';
        } else
        {
            if (p.sec%2==0)
                cout<<0<<' '; else
                cout<<m<<' ';
        }
    }
}
/*
*/