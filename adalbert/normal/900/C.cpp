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
typedef double ld;
const int arr=2e5;

int good[arr],a[arr];

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    set<int> setik;

    setik.insert(0);

    for (int i=1;i<=n;i++)
    {
        if (*setik.rbegin()<a[i])
            good[a[i]]--; else
        {
            int now=*setik.rbegin();
            setik.erase(now);
            if (*setik.rbegin()<a[i])
                good[now]++;
            setik.insert(now);
        }
        setik.insert(a[i]);
    }

    int ians=1;

    for (int i=1;i<=n;i++)
        if (good[i]>good[ians])
        ians=i;
    cout<<ians;
}