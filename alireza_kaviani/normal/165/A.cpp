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

    int n , ans = 0;
    cin >> n;

    vector<pii> vec;
    for(int i = 0 ;i < n; i++)
    {
        int x , y;
        cin >> x >> y;
        vec.push_back({x , y});
    }

    for(int i = 0 ; i < n; i++)
    {
        set<int> st;
        for(int j = 0 ;j < n ; j++)
        {
            if(vec[i].X == vec[j].X && vec[i].Y > vec[j].Y)
            {
                st.insert(1);
            }
            if(vec[i].X == vec[j].X && vec[i].Y < vec[j].Y)
            {
                st.insert(2);
            }
            if(vec[i].X > vec[j].X && vec[i].Y == vec[j].Y)
            {
                st.insert(3);
            }
            if(vec[i].X < vec[j].X && vec[i].Y == vec[j].Y)
            {
                st.insert(4);
            }
        }
        if(st.size() == 4)
        {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}