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

signed main()
{
    int a,b,c;
    cin>>a>>b>>c;

    int now=0;
    set<int> setik;
    while (1)
    {
        if (setik.count(a))
        {
            cout<<-1;
            return(0);
        }
        setik.insert(a);
        now++;
        a*=10;
        if (a/b==c)
        {
            cout<<now<<'\n';
            return(0);
        }

        a%=b;
    }
}