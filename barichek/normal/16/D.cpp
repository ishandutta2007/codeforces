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

int to_int(string s)
{
    stringstream stt;
    stt<<s;
    int res;
    stt>>res;
    return res;
}

int get_time(string s)
{
    return (s.substr(0,2)!="12")*to_int(s.substr(0,2))*60+to_int(s.substr(3));
}

main()
{
    int n;
    cin>>n;
    int ans=1;
    int last=0;
    getchar();
    int cnt_equal=0;
    while (n--)
    {
        string all;
        getline(cin,all);
        stringstream stt;
        stt<<all;
        string s,t;
        stt>>s>>t;
        s.erase(s.begin());
        int cur_time=get_time(s);
        char type=t.front();
        if (s=="12:00"&&type=='a')
            cur_time=0;
        else
            cur_time+=(type=='p')*12*60;
        if (cur_time<last)
            ans++,
            cnt_equal=1;
        elif (cur_time==last)
        {
            if (++cnt_equal==11)
                ans++,
                cnt_equal=1;
        }
        else
            cnt_equal=1;
        last=cur_time;
    }
    cout<<ans;
}