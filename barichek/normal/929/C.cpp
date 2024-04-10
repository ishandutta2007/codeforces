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
#define time ddfkjgofidhj
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int md=1e9+7;
const int arr=1e6;



signed main()
{
    int n,m,k;
    cin>>n>>m>>k;

    vector<pair<int,int> > vec;

    for (int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        vec.pb({a,1});
    }

    for (int i=1;i<=m;i++)
    {
        int a;
        cin>>a;
        vec.pb({a,2});
    }

    for (int i=1;i<=k;i++)
    {
        int a;
        cin>>a;
        vec.pb({a,3});
    }

    sort(vec.begin(),vec.end());

    int cnt1=0,cnt2=0,cnt3=0;

    int last=0;
    int ans=0;

    for (int i=0;i<vec.size();i++)
    {
        while (last!=vec.size() && vec[last].fir<=vec[i].fir*2)
        {
            if (vec[last].sec==1)
                cnt1++;
            if (vec[last].sec==2)
                cnt2++;
            if (vec[last].sec==3)
                cnt3++;
            last++;
        }

        if (vec[i].sec==1)
        {
            ans+=cnt2*(cnt2-1)/2*cnt3*(cnt3-1)*(cnt3-2)/6;
        }

        if (vec[i].sec==2)
        {
            ans+=cnt1*(cnt2-1)*cnt3*(cnt3-1)*(cnt3-2)/6;
        }

        if (vec[i].sec==3)
        {
            ans+=cnt1*cnt2*(cnt2-1)/2*(cnt3-1)*(cnt3-2)/2;
        }

        if (vec[i].sec==1)
                cnt1--;
        if (vec[i].sec==2)
                cnt2--;
        if (vec[i].sec==3)
                cnt3--;
    }

    cout<<ans;
}
/*
*/