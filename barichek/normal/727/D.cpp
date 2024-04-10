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
const ll md=1e9+7;
const ld eps=1e-10;

///---program start---///

vector<int> vh[10];
map<string,int> up;
map<int,string> up1;
int ukaz[arr];
bool use[arr];

main()
{
    up["S"]=0;
    up["M"]=1;
    up["L"]=2;
    up["XL"]=3;
    up["XXL"]=4;
    up["XXXL"]=5;
    for (auto i:up)
        up1[i.sec]=i.fir;
    vector<int> cnt;
    cnt.resize(6);
    for (auto &i:cnt)
        cin>>i;
    int n;
    cin>>n;
    vector<string> ans;
    ans.assign(n,"bleat");
    for (int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        if (s.find(',')==-1)
            cnt[up[s]]--,
            use[i]=true,
            ans[i]=s;
        else
        {
            string s1=s.substr(0,s.find(','));
            vh[up[s1]].pb(i);
        }
    }
    for (auto i:cnt)
        if (i<0) return cout<<"NO", 0;
    for (int i=0;i<6;i++)
    {
        if (i!=0)
        {
            while (cnt[i]>0&&ukaz[i-1]<vh[i-1].size())
            {
                if (use[vh[i-1][ukaz[i-1]]])
                {
                    ukaz[i-1]++;
                    continue;
                }
                cnt[i]--;
                ans[vh[i-1][ukaz[i-1]]]=up1[i];
                use[vh[i-1][ukaz[i-1]]]=true;
                ukaz[i-1]++;
            }
        }
        while (cnt[i]>0&&ukaz[i]<vh[i].size())
        {
            if (use[vh[i][ukaz[i]]])
            {
                ukaz[i]++;
                continue;
            }
            cnt[i]--;
            ans[vh[i][ukaz[i]]]=up1[i];
            use[vh[i][ukaz[i]]]=true;
            ukaz[i]++;
        }
    }
    for (auto i:ans)
        if (i=="bleat") return cout<<"NO", 0;
    cout<<"YES\n";
    for (auto i:ans)
        cout<<i<<"\n";
}