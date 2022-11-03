#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define left dogjreg
#define right dgfdogjreg
#define int ll
typedef long long ll;
typedef double ld;
const int arr=2e5;

int md=1e9+7;

int good[arr],a[arr];

int pow_(int u, int step)
{

    if (step==0)
        return(1);
    if (step%2)
    {
        return(pow_(u,step-1)*ll(2)%md);
    } else
    {
        int now=pow_(u,step/2);
        return(now*now%md);
    }
}

int get(int u)
{

    return(pow_(2,u-1));
}

int get(int y, int x)
{
    return(get(y/x));
}

signed main()
{


    int x,y;
    cin>>x>>y;
    if (y%x!=0)
    {
        cout<<0;
        return(0);
    }

    y/=x;

    vector<int> vec;
    for (int i=1;i*i<=y;i++)
    {
        if (y%i==0)
        {
            vec.pb(i);
            if (y/i!=i)
                vec.pb(y/i);
        }
    }

    sort(vec.begin(),vec.end());

    int ans=0;
    ans+=get(y,1);

    ans%=md;
    map<int,int> mp;
    mp[1]=1;

    for (int i=1;i<vec.size();i++)
    {
        int now=0;
        for (int j=1;j*j<=vec[i];j++)
        {
            if (vec[i]%j==0)
            {

                now+=mp[j];
                now%=md;
                if (vec[i]/j!=j)
                {

                    now+=mp[vec[i]/j];
                    now%=md;
                }
            }
        }


        ans-=now*get(y,vec[i])%md;
        ans+=md;
        ans%=md;
        mp[vec[i]]=-now;

    }

    cout<<ans;
}