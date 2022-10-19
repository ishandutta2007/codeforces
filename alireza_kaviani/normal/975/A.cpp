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

vector<int> root(vector<int> a)
{
    vector<int> cnt(26 , 0);
    for(int i = 0; i < a.size() ; i++)
    {
        cnt[a[i]]++;
    }

    vector<int> ans;
    for(int i = 0; i < 26 ; i++)
    {
        if(cnt[i] >= 1)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

int main()
{
    fast_io;
    int n, ans = 0;
    cin >> n;

    vector<int> a[n];
    for(int i = 0 ;i < n ; i++)
    {
        string s;
        cin >> s;
        a[i] = vector<int>(s.size());
        for(int j = 0; j < s.size() ; j++)
        {
            a[i][j] = ((int)s[j]) - 97;
        }
        Sort(a[i]);
    }
    map<vector<int> , bool> mp;

    for(int i = 0; i < n ; i++)
    {
        if(mp[root(a[i])] == false)
        {
            mp[root(a[i])] = true;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}