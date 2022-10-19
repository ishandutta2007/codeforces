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

int main()
{
    fast_io;

    int n, k;
    cin >> n >> k;

    set<int> st;
    vector<int> ans;
    for(int i = 0 ;i < n ; i++)
    {
        int t;
        cin >> t;
        int s = st.size();
        st.insert(t);
        if(st.size() != s)
        {
            ans.push_back(i + 1);
        }
    }

    if(st.size() < k)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        for(int i = 0 ; i < k ; i++)
        {
            cout << ans[i] << ends;
        }
    }

    return 0;
}