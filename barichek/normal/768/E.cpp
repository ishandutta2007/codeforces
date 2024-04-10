#pragma GCC optimize("O3")
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

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

map<pair<set<int>,int>,int> sg;
map<pair<set<int>,int>,int> use;

int calc_sg(pair<set<int>,int> x)
{
    if (use[x]) return sg[x];
    use[x]=true;
    bool used[500];
    memset(used,0,sizeof(used));
    set<int> setik=x.fir;
    for (int i=1;i<=x.sec;i++)
        if (!setik.count(i))
        {
            setik.insert(i);
            used[calc_sg(mp(setik,x.sec-i))]=true;
            setik.erase(i);
        }
    for (int i=0;i<500;i++)
        if (!used[i])
            return sg[x]=i;
}

int ans[arr];

main()
{
    ans[1]=1;
    ans[2]=1;
    ans[3]=2;
    ans[4]=2;
    ans[5]=2;
    ans[6]=3;
    ans[7]=3;
    ans[8]=3;
    ans[9]=3;
    ans[10]=4;
    ans[11]=4;
    ans[12]=4;
    ans[13]=4;
    ans[14]=4;
    ans[15]=5;
    ans[16]=5;
    ans[17]=5;
    ans[18]=5;
    ans[19]=5;
    ans[20]=5;
    ans[21]=6;
    ans[22]=6;
    ans[23]=6;
    ans[24]=6;
    ans[25]=6;
    ans[26]=6;
    ans[27]=6;
    ans[28]=7;
    ans[29]=7;
    ans[30]=7;
    ans[31]=7;
    ans[32]=7;
    ans[33]=7;
    ans[34]=7;
    ans[35]=7;
    ans[36]=8;
    ans[37]=8;
    ans[38]=8;
    ans[39]=8;
    ans[40]=8;
    ans[41]=8;
    ans[42]=8;
    ans[43]=8;
    ans[44]=8;
    ans[45]=9;
    ans[46]=9;
    ans[47]=9;
    ans[48]=9;
    ans[49]=9;
    ans[50]=9;
    ans[51]=9;
    ans[52]=9;
    ans[53]=9;
    ans[54]=9;
    ans[55]=10;
    ans[56]=10;
    ans[57]=10;
    ans[58]=10;
    ans[59]=10;
    ans[60]=10;
    //for (int i=1;i<=60;i++)
      //  cout<<"ans["<<i<<"]="<<calc_sg(mp(set<int>{},i))<<";\n";
    fast;
    int n;
    cin>>n;
    vi a;
    a.clear();
    a.resize(n);
    for (auto &i:a)
        cin>>i;
    int res=0;
    for (auto i:a)
        res^=ans[i];
    cout<<(res?"NO":"YES");
}