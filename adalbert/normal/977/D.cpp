#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
const int arr=6e5;
int a[arr],cnt2[arr],cnt3[arr];

bool check(int i, int j)
{
    if (cnt3[i]==cnt3[j])
        return(cnt2[i]<cnt2[j]); else
        return(cnt3[i]>cnt3[j]);
}

signed main()
{
    int n;
    cin>>n;
    vector<int> vec;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        int now=a[i];
        while (now%3==0)
        {
            cnt3[i]++;
            now/=3;
        }
        while (now%2==0)
        {
            cnt2[i]++;
            now/=2;
        }

        vec.pb(i);
    }

    sort(vec.begin(),vec.end(),check);

    for (auto i:vec)
        cout<<a[i]<<' ';
}
/*
*/