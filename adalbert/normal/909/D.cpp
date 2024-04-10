#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define left dogjreg
#define right dgfdogjreg
typedef long long ll;
typedef double ld;
const int arr=2e5+1000;

int dp[5010][5010];
const int md=1e9+7;
char a[5010];
signed main()
{
    fast;
    string st;
    cin>>st;
    vector<pair<char,int> > vec;

    vec.pb({'1',0});
    for (auto i:st)
        if (i!=vec.back().fir)
            vec.pb({i,1}); else
            vec[vec.size()-1].sec++;
    reverse(vec.begin(),vec.end());
    vec.pop_back();
    reverse(vec.begin(),vec.end());
    int cnt=0;
    while(vec.size()>1)
    {
        cnt++;

        vector<pair<char,int> > vv;
        vv.pb({'1',0});
        for (int i=0;i<vec.size();i++)
        {
            vec[i].sec-=2;
        }
        vec[0].sec++;
        vec[vec.size()-1].sec++;
        for (int i=0;i<vec.size();i++)
            if (vec[i].sec>0)
            if (vec[i].fir==vv.back().fir)
                vv[vv.size()-1].sec+=vec[i].sec; else
                vv.pb({vec[i]});

        vec=vv;
        reverse(vec.begin(),vec.end());
        vec.pop_back();
        reverse(vec.begin(),vec.end());

    }
    cout<<cnt;
}