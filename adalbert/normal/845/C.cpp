#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pii;
typedef vector <pii> vii;
const ld pi = acos(-1);
const int arr = 4*1e5+100;
const ll md = 1e9+7;
const ll base=31;
const int AaA = 'a'-'A';
ld eps=1e-7;
int a[arr];
signed main()
{
    int n;
    cin>>n;
    vector<pair<int,int> > vec;
    for (int i=1;i<=n;i++)
    {
        int l,r;
        cin>>l>>r;
        vec.pb({l,-1});
        vec.pb({r,1});
    }
    sort(vec.begin(),vec.end());
    int now=0;
    for (int i=0;i<vec.size();i++)
    {
        //cout<<vec[i].fir<<' '<<vec[i].sec<<'\n';
        now-=vec[i].sec;
        if (now>2)
        {
            cout<<"NO";
            return(0);
        }
    }
    cout<<"YES";
}