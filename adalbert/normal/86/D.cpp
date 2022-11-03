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
const int bigarr=1e6+100;
const int arr=2e5+100;

struct QQ
{
    int l,r,nom;
    QQ(int left, int right, int nomber)
    {
        l=left;
        r=right;
        nom=nomber;
    }
};

const bool operator < (const QQ &i, const QQ &j)
{
    return(i.r<j.r);
}

int ml,mr;
ll mans;

int cnt[bigarr],a[arr];
ll ans[arr];
int bs=220;
vector<QQ> vec[arr];

void add(int u)
{
    mans+=(cnt[a[u]]*2+1)*a[u];
    cnt[a[u]]++;
}

void dell(int u)
{
    mans+=(-cnt[a[u]]*2+1)*a[u];
    cnt[a[u]]--;
}

signed main()
{
    fast;
    int n,t;
    cin>>n>>t;

    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for (int i=1;i<=t;i++)
    {
        int l,r;
        cin>>l>>r;
        vec[l/bs].pb(QQ(l,r,i));
    }



    for (int i=0;i<=n/bs;i++)
    {
        sort(vec[i].begin(),vec[i].end());
        for (auto j:vec[i])
        {

            while(ml<j.l)
            {
                dell(ml);
                ml++;
            }
            while (ml>j.l)
            {
                ml--;
                add(ml);
            }

            while (mr<j.r)
            {
                mr++;
                add(mr);
            }

            while (mr>j.r)
            {
                dell(mr);
                mr--;
            }

            ans[j.nom]+=mans;
        }
    }

    for (int i=1;i<=t;i++)
        cout<<ans[i]<<'\n';
}
/*
*/