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

map<string , int> mp;
vector<string> removei(vector<string> vec , int ind)
{
    vector<string> ans;
    for(int i = 0 ; i < vec.size() ; i++)
    {
        if(i != ind)
        {
            ans.push_back(vec[i]);
        }
        else
        {
            ans.push_back("empty");
        }
    }
    return ans;
}

int main()
{
    fast_io;

    int n;
    cin >> n;

    vector<string> vec = {"Power" , "Time" , "Space" , "Soul" , "Reality" , "Mind"};
    mp["purple"] = 0;
    mp["green"] = 1;
    mp["blue"] = 2;
    mp["orange"] = 3;
    mp["red"] = 4;
    mp["yellow"] = 5;

    for(int i = 0 ;i < n ; i++)
    {
        string s;
        cin >> s;
        vec = removei(vec , mp[s]);
    }

    cout << vec.size() - n << endl;
    for(string i : vec)
    {
        if(i != "empty")
        {
            cout << i << endl;
        }
    }

    return 0;
}