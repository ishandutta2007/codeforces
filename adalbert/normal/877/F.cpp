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
typedef long long ll;
typedef long double ld;
const int arr=4e5;
int cnt=0;
map<ll,int> mp_;
int mp[arr];
ll a[arr], left, right, ans;
int gt[arr],gts[arr],gtr[arr];
int k;

void clear_()
{
    ans=0;
    left=0;
    right=0;
    mp[gt[0]]=1;
}

void plussleft()
{
    mp[gt[left]]--;
    ans-=ll(mp[gts[left]]);
    left++;
}
void minusleft()
{
    left--;
    ans+=ll(mp[gts[left]]);
    mp[gt[left]]++;
}

void minusright()
{
    mp[gt[right]]--;
    ans-=ll(mp[gtr[right]]);
    right--;
}

void plussright()
{
    right++;
    ans+=ll(mp[gtr[right]]);
    mp[gt[right]]++;

}



void do_(int &l, int &r)
{
    while (right<r)
        plussright();
    while (left>l)
        minusleft();
    while (right>r)
        minusright();
    while (left<l)
        plussleft();
}

int t[arr];

int bs=300;
vector<pair<pair<int,int>, int > > vec[2000];

ll an[arr];

signed main()
{
    fast;
    int n;
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&t[i]);
    }

    mp_[0];
    mp_[k];
    mp_[-k];
    for (int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        if (t[i]==2)
            a[i]=-a[i];
        a[i]=a[i-1]+a[i];
        mp_[a[i]];
        mp_[a[i]+k];
        mp_[a[i]-k];
    }



    int q;
    scanf("%d",&q);



    for (int i=1;i<=q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        l--;

        vec[l/bs].pb({{r,l},i});
    }

    cnt=0;
    for (auto i:mp_)
    {
        mp_[i.fir]=++cnt;
    }

    for (int i=0;i<=n;i++)
    {
        gt[i]=mp_[a[i]];
        gts[i]=mp_[a[i]+k];
        gtr[i]=mp_[a[i]-k];
    }

    clear_();

    for (int i=0;i<=n/bs+1;i++)
    {
        sort(vec[i].begin(),vec[i].end());
        for (int j=0;j<vec[i].size();j++)
        {
            do_(vec[i][j].fir.sec,vec[i][j].fir.fir);
                an[vec[i][j].sec]=ans;
        }

    }

    for (int i=1;i<=q;i++)
        cout<<an[i]<<'\n';
}
/*
!!! https://pastebin.com/jHpxMZq3
*/