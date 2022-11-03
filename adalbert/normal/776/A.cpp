#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define int ll
#define y1 humiuyn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
signed main()
{
    int n;
    string st1,st2;
    cin>>st1>>st2;
    cin>>n;
    cout<<st1<<' '<<st2<<'\n';
    for (int i=1;i<=n;i++)
    {
        string new_,next;
        cin>>new_>>next;
        if (new_==st1)
            st1=next; else
            st2=next;
        cout<<st1<<' '<<st2<<'\n';
    }
}