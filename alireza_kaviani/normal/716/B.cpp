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

int cnt[26];
string sub;
bool check(string t)
{
    if(t.size() != 26)      return 0;
    fill(cnt , cnt + 26 , 0);
    sub = "";
    for(int i = 0 ; i < t.size() ; i++)
    {
        if(t[i] != '?')
        {
            cnt[t[i] - 65]++;
            if(cnt[t[i] - 65] > 1)
            {
                return 0;
            }
        }
    }

    int now = 0;
    for(int i = 0 ; i < t.size() ; i++)
    {
        if(t[i] == '?')
        {
            for(; now < 26; now++)
            {
                if(cnt[now] == 0)
                {
                    break;
                }
            }
            sub += now + 65;
            cnt[now]++;
        }
        else
        {
            sub += t[i];
        }
    }
    return 1;
}

int main()
{
    fast_io;

    string s;
    cin >> s;

    for(int i = 0 ; i < s.size() ; i++)
    {
        bool t = check(s.substr(i , 26));
        if(t)
        {
            for(int j = i ; j < s.size() ; j++)
            {
                if(j < i + 26)
                {
                    s[j] = sub[j - i];
                }
                else
                {
                    s[j] = (s[j] == '?' ? 'A' : s[j]);
                }
            }
            cout << s << endl;
            return 0;
        }
        s[i] = (s[i] == '?' ? 'A' : s[i]);
    }
    cout << -1 << endl;

    return 0;
}