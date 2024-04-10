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

#define int ll

bool is_alfa(char a)
{
    return a>='a'&&a<='z';
}

int to_int(string s)
{
    stringstream stt;
    stt<<s;
    int res;
    stt>>res;
    //cout<<res<<" !!!\n";
    return res;
}

string get_without(string s)
{
    string res="";
    for (auto i:s)
        if (i!='.')
            res+=i;
    //cout<<res<<" !!!\n";
    return res;
}

int get(string& s)
{
    if (s.length()<=3)
        return to_int(s)*100;
    int res=0;
    //cout<<s.substr(0,s.length()-3)<<" || "<<s.substr(s.length()-2,2)<<" !\n";
    if (s[s.length()-3]=='.')
        return to_int(get_without(s.substr(0,s.length()-3)))*100+to_int(s.substr(s.length()-2,2));
    else
        return to_int(get_without(s))*100;
}

string get_ans(int a)
{
    int rem=a%100;
    a/=100;
    stringstream stt;
    stt<<a;
    string use;
    stt>>use;
    reverse(all(use));
    string res="";
    for (int i=0;i<use.length();i++)
    {
        if (i!=0&&i%3==0) res+='.';
        res+=use[i];
    }
    //cout<<res<<" !!!\n";
    reverse(all(res));
    if (rem!=0)
    {
        res+='.';
        res=res+char(rem/10+'0');
        res=res+char(rem%10+'0');
    }
    return res;
}

string work(string s)
{
    //if (s.back()=='.') return s.substr(0,s.length()-1);
    return s;
}

main()
{
    string s;
    cin>>s;
    vector<string> use;
    use.clear();
    string cur="";
    for (auto i:s)
        if (is_alfa(i))
        {
            if (!cur.empty())
            {
                use.pb(cur);
                cur="";
            }
        }
        else
        {
            cur+=i;
        }
    use.pb(cur);
    int res=0;
    for (auto i:use)
        //cout<<i<<" "<<res<<" !!\n",
        res+=get(i);
    //cout<<res<<" !\n";
    cout<<work(get_ans(res));
}