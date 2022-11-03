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
int n,k;
int get(multiset<int> all, multiset<int> now, int sum)
{
    int kk=k;
    while (!all.empty() && !now.empty() && kk && *now.begin()<*all.rbegin())
    {
        sum+=*all.rbegin();
        sum-=*now.begin();
        all.erase(all.find(*all.rbegin()));
        now.erase(now.find(*now.begin()));
        kk--;
    }
    return(sum);
}

int a[300];

int main()
{

    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    int ans=-1e18;

    for (int l=1;l<=n;l++)
    {
        multiset<int> all;
        for (int j=1;j<=n;j++)
            all.insert(a[j]);
        multiset<int> now;
        int sum=0;
        for (int j=l;j<=n;j++)
        {
            sum+=a[j];
            all.erase(all.find(a[j]));
            now.insert(a[j]);
            ans=max(ans,get(all,now,sum));
        }
    }

    cout<<ans;
}
/*

*/