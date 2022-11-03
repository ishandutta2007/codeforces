
 #include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int md=1e9+7;
const int arr=7e5;

int a[arr],b[arr];
int x,d;

vector<int> vec;

void solve(int start, int n)
{
    if (n==0)
        return;
    int now=1;
    while ((1ll<<(now+1))-1<=n)
        now++;

    for (int i=0;i<now;i++)
        vec.pb(start);
    solve(start+d+10,n-(1ll<<now)+1);
}

int getdeep(int u)
{
    int res=0;
    while ((1ll<<(res+1))<=u)
    {
        res++;
    }
    return(res);
}

int nom[500],go[500];

signed main()
{
    int n;
    cin>>n;
    while (n--)
    {
        int type,x,k;
        cin>>type;

        if (type==1)
        {
            cin>>x>>k;
            k=-k;
            int now=getdeep(x);
            k%=(1ll<<now);
            k+=(1ll<<now);
            k%=(1ll<<now);

            nom[now]+=k;
            nom[now]%=(1ll<<now);
        } else
        if (type==2)
        {
            cin>>x>>k;
            //k=-k;
            int now=getdeep(x);
            k%=(1ll<<now);
            k+=(1ll<<now);
            k%=(1ll<<now);

            go[now]+=k;
            go[now]%=(1ll<<now);
        } else
        {
            cin>>x;
            int now=getdeep(x);

            while (now>=0)
            {
                cout<<x<<' ';
                int start=(1ll<<now);
                int pl=x-start;
                pl-=nom[now];
                pl+=(1ll<<now);
                pl%=(1ll<<now);
                pl+=start;


                if (now!=0)
                {
                    pl-=start;
                    pl+=go[now];
                    pl%=(1ll<<(now));
                    pl+=start;


                    pl/=2;
                    pl-=start/2;

                    pl+=nom[now-1];
                    pl+=(1ll<<(now-1));
                    pl%=(1ll<<(now-1));
                    pl+=start/2;
                }
                x=pl;
                now--;
            }
            cout<<'\n';
        }
    }
}