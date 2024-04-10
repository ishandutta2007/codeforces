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

string ans1,ans2;
vector<vector<string>> a;
vector<vi> b(arr);

unordered_map<string,int> vh;
int cnt_vh;

int vall[3*ar];

void set_bit(int &cur_res,int bit,int val)
{
    memset(vall,0,sizeof(vall));
    //cerr<<"!!set_bit :: "<<bit<<" "<<val<<"\n";
    vall[0]=val;
    cur_res=0;
    for (int i=0;i<a.size();i++)
    {
        if (b[i].size()==3)
        {
            //cerr<<"gavno1\n";
            int val1,val2;
            val1=vall[b[i][1]];
            val2=vall[b[i][2]];
            //cerr<<"val1 val2 :: "<<val1<<" "<<val2<<"\n";
            //cerr<<"op :: "<<op<<"\n";
            int res;
            if (a[i][1]=="XOR")
                res=val1^val2;
            if (a[i][1]=="AND")
                res=val1&val2;
            if (a[i][1]=="OR")
                res=val1|val2;
            vall[b[i][0]]=res;
        }
        else
        {
            //cerr<<"gavno2\n";
            vall[b[i][0]]=a[i][1][bit]-'0';
        }
        //cerr<<"after "<<i<<" :: "<<cur_res<<"\n";
    }
    for (int i=1;i<3*ar;i++)
        cur_res+=vall[i];
    //cerr<<"!!res :: "<<cur_res<<"\n";
}

bool is_bad_string(string &s)
{
    if (s=="AND") return true;
    if (s=="OR") return true;
    if (s=="XOR") return true;
    if (s=="?") return false;
    if (s.front()=='0') return true;
    if (s.front()=='1') return true;
    if (s==":=") return true;
    return false;
}

void add(int i,string s)
{
    //cerr<<"add :: "<<i<<" "<<s<<"\n";
    if (!is_bad_string(s))
    {
        if (!vh[s]&&s!="?")
            vh[s]=++cnt_vh;
        b[i].pb(vh[s]);
    }
    else
    {
        a[i].pb(s);
    }
}

main()
{
    vh["?"]=0;
    int n,m;
    cin>>n>>m;
    getchar();
    ans1.clear();
    ans2.clear();
    a.clear();
    a.resize(n);
    for (int i=0;i<n;i++)
    {
        string ss;
        getline(cin,ss);
        string s;
        s.clear();
        for (auto j:ss)
            if (j==' ')
                add(i,s),
                s.clear();
            else
                s+=j;
        if (!s.empty())
            add(i,s);
    }
    /*
    for (int i=0;i<n;i++)
    {
        cerr<<i<<" :::\n";
        for (auto j:a[i])
            cerr<<j<<" ";
        cerr<<"\n";
        for (auto j:b[i])
            cerr<<j<<" ";
        cerr<<"\n";
    }
    */
    for (int i=0;i<m;i++)
    {
        int res0,res1;
        set_bit(res0,i,0);
        set_bit(res1,i,1);
        if (res0==res1)
            ans1+='0',
            ans2+='0';
        else
        {
            if (res0<res1)
                ans1+='0',
                ans2+='1';
            else
                ans1+='1',
                ans2+='0';
        }
    }
    cout<<ans1<<"\n";
    cout<<ans2<<"\n";
}