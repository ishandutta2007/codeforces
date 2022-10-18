#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int maxint=numeric_limits<int>::max();
const ll maxll=numeric_limits<ll>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

vector<string> split(string s,char loop=' ')
{
    vector<string> res;
    res.clear();
    string cur;
    cur.clear();
    for (auto i:s)
        if (i==loop)
        {
            res.pb(cur);
            cur.clear();
        }
        else
            cur+=i;
    if (!cur.empty())
        res.pb(cur);
    return res;
}

int to_int(string s)
{
    stringstream stt;
    stt<<s;
    int res;
    stt>>res;
    return res;
}

int pointer=0;
vector<string> ans[5*arr];
vector<string> vec;
int max_deep=0;

void dfs(int deep=0)
{
    max_deep=max(max_deep,deep);
    ans[deep].pb(vec[pointer++]);
    int cur_cnt=to_int(vec[pointer++]);
    while (cur_cnt--)
        dfs(deep+1);
}

main()
{
    string s;
    cin>>s;
    vec=split(s,',');
    for (pointer=0;pointer<vec.size();)
        dfs();
    cout<<max_deep+1<<"\n";
    for (int i=0;i<=max_deep;i++)
    {
        for (auto j:ans[i])
            cout<<j<<" ";
        cout<<"\n";
    }
}