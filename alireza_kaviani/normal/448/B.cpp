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

bool automaton(string s , string t)
{
    int now = 0;
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(t[now] == s[i])
        {
            now++;
        }
    }
    return (now == t.size());
}

bool Array(string s , string t)
{
    if(s.size() != t.size())    return 0;
    int cnt[26] = {};
    for(int i = 0 ; i < s.size() ; i++)
    {
        cnt[s[i] - 97]++;
        cnt[t[i] - 97]--;
    }
    for(int i = 0 ; i < 26 ; i++)
    {
        if(cnt[i] != 0)
        {
            return 0;
        }
    }
    return 1;
}

bool both(string s , string t)
{
    int cnt[26] = {};
    for(int i = 0 ; i < s.size() ; i++)
    {
        cnt[s[i] - 97]++;
    }
    for(int i = 0 ; i < t.size() ; i++)
    {
        cnt[t[i] - 97]--;
    }
    for(int i = 0 ; i < 26 ; i++)
    {
        if(cnt[i] < 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    fast_io;

    string s , t;
    cin >> s >> t;

    if(automaton(s , t))
    {
        cout << "automaton" << endl;
        return 0;
    }
    if(Array(s , t))
    {
        cout << "array" << endl;
        return 0;
    }
    if(both(s , t))
    {
        cout << "both" << endl;
        return 0;
    }
    cout << "need tree" << endl;

    return 0;
}