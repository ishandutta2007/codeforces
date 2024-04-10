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
const int arr=5e5;

int md=1e9+7;

int len[1000][1000];

signed main()
{
    int h1,a1,c,h2,a2;
    cin>>h1>>a1>>c>>h2>>a2;

    vector<string> vec;
    while (h2>0)
    {
        if (h2-a1<=0)
        {
            h2-=a1;
            vec.pb("STRIKE");
        } else
        if (h1-a2<=0)
        {
            h1+=c;
            vec.pb("HEAL");
        } else
        {
            h2-=a1;
            vec.pb("STRIKE");
        }

        h1-=a2;
    }

    cout<<vec.size()<<'\n';
    for (auto i:vec)
        cout<<i<<'\n';
}