#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
inline int input(){int n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

void split(vector<string> &ans , string addres)
{
    addres += '/';
    string s = "";
    if(addres[0] == '/')    ans.clear();
    for(int i = (addres[0] == '/' ? 1 : 0) ; i < addres.size() ; i++)
    {
        s += addres[i];
        if(addres[i] == '/')
        {
            if(s == "../")  ans.pop_back();
            else    ans.push_back(s);
            s = "";
        }
    }
}

int main()
{
    fast_io;

    int q;
    cin >> q;

    vector<string> ans;
    while(q--)
    {
        string s;
        cin >> s;
        if(s == "pwd")
        {
            cout << "/";
            for(int i = 0 ; i < ans.size() ; i++)   cout << ans[i];
            cout << endl;
        }
        else
        {
            string addres;
            cin >> addres;
            split(ans , addres);
        }
    }

    return 0;
}