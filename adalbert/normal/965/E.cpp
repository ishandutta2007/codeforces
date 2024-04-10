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

const int arr=3e5+100;
const int base=31;

int go[300100][30],cnt[300100],pred[300000];
bool use[300100];
int last=1;

set<pair<int,int> > setik;

void add(string st)
{
    int now=1;
    int len=0;
    for (auto i:st)
    {
        len++;
        if (go[now][i-'a']==0)
        {
            go[now][i-'a']=++last;
            pred[last]=now;
            setik.insert({len,last});
        }
        now=go[now][i-'a'];
        cnt[now]++;
    }
}

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        string st;
        cin>>st;
        add(st);
    }

    int ans=0;
    use[1]=1;

    while (n)
    {
        pair<int,int> now=*setik.begin();
        setik.erase(now);
        int u=now.sec;
        while (u!=1 && cnt[u]!=0)
        {
            cnt[u]--;
            u=pred[u];
        }
        if (u==1)
        {
            n--;
            ans+=now.fir;
        }
    }

    cout<<ans;


}