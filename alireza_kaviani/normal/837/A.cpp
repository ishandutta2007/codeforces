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

vector<string> split(string s)
{
    vector<string> ans;
    string t = "";
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(s[i] == ' ')
        {
            ans.push_back(t);
            t = "";
        }
        else
        {
            t += s[i];
        }
    }
    ans.push_back(t);
    return ans;
}

int main()
{
    int n , ans = 0;
    string s;
    cin >> n;
    getchar();
    getline(cin , s);
    vector<string> words = split(s);

    for(int i = 0 ; i < words.size() ; i++)
    {
        int t = 0;
        for(int j = 0 ; j < words[i].size() ; j++)
        {
            if(words[i][j] < 97)    t++;
        }
        ans = max(ans , t);
    }
    cout << ans << endl;

    return 0;
}