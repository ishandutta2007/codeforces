#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define fir first
#define sec second
#define pb push_back
#define int long long
using namespace std;
typedef double ld;
typedef long long ll;
const int arr=5e5;
int mn[arr],ans[arr];
pair<int,int> a[arr];
void bad()
{
    cout<<-1;
    exit(0);
}
///---program start---///
main()
{
    int n,w;
    cin>>n>>w;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].fir;
        a[i].sec=i;
    }
    sort(a+1,a+1+n);
    reverse(a+1,a+1+n);
    for (int i=1;i<=n;i++)
    {
        mn[i]=(a[i].fir+1)/2;
        w-=mn[i];
    }
    if (w<0)
        bad();
    mn[0]=1e9;
    while (w--)
    {
        int now=1;
        while (mn[now]==a[now].fir || mn[now]==mn[now-1])
        {
            now++;
            if (now>n) bad();
        }
        mn[now]++;
    }
    for (int i=1;i<=n;i++)
        ans[a[i].sec]=mn[i];
    for (int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
}