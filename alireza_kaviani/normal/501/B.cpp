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

map<string , string> child;
string find(string s)
{
    if(child[s] == "-1")
    {
        return s;
    }
    return find(child[s]);
}

int main()
{
    fast_io;

    int n;
    cin >> n;

    set<string> st;
    for(int i = 0 ; i < n ; i++)
    {
        string s , s2;
        cin >> s >> s2;

        if(child[s] == "")
        {
            st.insert(s);
        }
        child[s] = s2;
        child[s2] = "-1";
    }

    cout << st.size() << endl;
    for(auto &i : st)
    {
        cout << i << ends << find(i) << endl;
    }

    return 0;
}