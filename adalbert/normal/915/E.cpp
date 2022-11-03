#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define time pdojegoritg
#define left eorgjrptgj
#define right rtyjtokh
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=5e5+100;

int main()
{
    fast;
    int n,q;
    cin>>n>>q;
    set<pair<pair<int,int>,int> > setik;
    setik.insert({{1,n},1});
    int ans=n;
    while (q--)
    {
        int l,r,type;
        cin>>l>>r>>type;
        pair<pair<int,int>,int>  now={{l,-1e9},type};
        set<pair<pair<int,int>,int> >  :: iterator u=setik.upper_bound(now);
        if (u!=setik.begin())
        {
            u--;
            if ((*u).fir.sec>=l)
            {
                pair<pair<int,int>,int> now=*u;
                setik.erase(now);
                ans-=(now.fir.sec-now.fir.fir+1)*now.sec;
                if (now.fir.sec>r)
                {
                    setik.insert({{r+1,now.fir.sec},now.sec});
                    ans+=(now.fir.sec-r)*now.sec;
                }

                now.fir.sec=l-1;

                ans+=(now.fir.sec-now.fir.fir+1)*now.sec;
                setik.insert(now);
            }
        }
        u=setik.upper_bound(now);
        //cout<<"change"<<(*u).fir.fir<<' '<<(*u).fir.sec<<'\n';

        while (u!=setik.end() && (*u).fir.fir<=r)
        {
            //cout<<"change"<<(*u).fir.fir<<' '<<(*u).fir.sec<<'\n';
            if ((*u).fir.sec>r)
            {
                //cout<<'!'<<'\n';
                pair<pair<int,int>,int> now=*u;
                setik.erase(now);
                ans-=(now.fir.sec-now.fir.fir+1)*now.sec;
                now.fir.fir=r+1;

                ans+=(now.fir.sec-now.fir.fir+1)*now.sec;
                setik.insert(now);
                break;
            } else
            {
                ans-=((*u).fir.sec-(*u).fir.fir+1)*(*u).sec;
                setik.erase(*u);
                u=setik.upper_bound({{l,-1e9},type});
            }

        }
        ans+=(r-l+1)*(type-1);
        setik.insert({{l,r},type-1});
        cout<<ans<<'\n';

    }
}
/*
3
1
2 2 1

*/