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
#define get rgjeoig
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=5e5+100;

int cnt[1000100];

bool check(pair<int,int> i, pair<int,int> j)
{
    return(i.fir*j.sec>i.sec*j.fir);
}

signed main()
{
    int n;
    cin>>n;
    int ans=0;

    vector<pair<int,int> > vec;

    for (int i=1;i<=n;i++)
    {
        string st;
        cin>>st;
        int now=0;
        int sum1=0,sum2=0;
        for (auto i:st)
        {
            if (i=='s')
                sum1++; else
                sum2++;
            if (i=='h')
                now+=sum1;
        }
        ans+=now;
        vec.pb({sum1,sum2});
    }

    sort(vec.begin(),vec.end(),check);

    int sum=0;

    reverse(vec.begin(),vec.end());

    for (auto i:vec)
    {
        ans+=sum*i.fir;
        sum+=i.sec;
    }
    cout<<ans;
}
/*
*/