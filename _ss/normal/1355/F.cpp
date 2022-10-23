#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define all(vr) vr.begin(),vr.end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
//#define TEST
namespace myrand
{
    mt19937 mt(chrono::system_clock::now().time_since_epoch() / chrono::microseconds(1));
    ll Int(ll l,ll r) {return uniform_int_distribution<ll> (l,r)(mt);}
}

using namespace myrand;
const int lim=1e9,N=1e3;
const ll inf=1e18;
int X;

ll gcd(ll a,ll b)
{
    while (b)
    {
        ll r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int ask(ll Q)
{
    #ifndef TEST
        cout<<"? "<<Q<<endl;
        int x;
        cin>>x;
        return x;
    #else
        return gcd(X,Q);
    #endif // TEST
}

int cnt_divi(int x)
{
    int res=1;
    for (int i=2;i*i<=x;i++)
    {
        int d=1;
        while (x%i==0) x/=i,d++;
        res*=d;
    }
    if (x>1) res*=2;
    return res;
}

void ans(int x)
{
    #ifndef TEST
        cout<<"! "<<x<<endl;
    #else
        int d=cnt_divi(X);
        if (abs(x-d)<=7 || (d*2>=x && x*2>=d)) cout<<"AC"<<endl;
        else cout<<"WA "<<X<<" "<<d<<" "<<x<<" "<<endl;
    #endif // TEST
}

vector<int> snt;
int mark[N+10];

void sieve()
{
    for (int i=2;i<=N;i++)
        if (!mark[i])
        {
            snt.pb(i);
            for (int j=2*i;j<=N;j+=i) mark[j]=1;
        }
}

int main()
{
    sieve();
    int t;
    #ifndef TEST
        cin>>t;
    #else
        t=Int(10,100);
        //t=1;
    #endif // TEST
    while (t--)
    {
        #ifndef TEST
        #else
            X=Int(1e8,1e9);
            //X=466048778;
        #endif // TEST
        vector<int> divi,vt;
        ll val=1,sl=0;
        for (int x : snt)
            if (val<=inf/x) val*=x,vt.pb(x);
            else
            {
                int t=ask(val);
                for (int y : vt)
                    if (t%y==0) divi.pb(y);
                vt.clear();
                sl++;
                if (sl==17) break;
                val=x;
                vt.pb(x);
            }
        val=1;
        int res=1;
        for (int x : divi)
        {
            ll tx=1;
            while (tx*x<=lim) tx*=x;
            if (val<=inf/tx) val*=tx;
            else
            {
                int t=ask(val);
                for (int y : vt)
                {
                    int d=1;
                    while (t%y==0) t/=y,d++;
                    res*=d;
                }
                vt.clear();
                val=tx;
            }
            vt.pb(x);
        }
        int t=ask(val);
        for (int y : vt)
        {
            int d=1;
            while (t%y==0) t/=y,d++;
            res*=d;
        }
        if (res==2) ans(9);
        else ans(res*2);
    }
    return 0;
}