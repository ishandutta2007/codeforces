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
#define pb                          push_back
#define ppb                         pop_back
#define pf                          push_front
#define ppf                         pop_front
#define X                           first
#define Y                           second
#define Mp                           make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define out                         freopen("out.txt","w",stdout)
#define in                          freopen("in.txt","r",stdin)

int main()
{
    vector<int> l(10,0);
    bool b=false;
    for(int i=0;i<6;i++)
    {
        int t;
        cin >> t;
        l[t]++;
        if(l[t]>=4)
        {
            l[t]%=4;
            b=true;
        }
    }

    int ans=0;
    for(int i=0;i<10;i++)
    {
        if(l[i]>0 && l[i]<=6)
        {
            ans++;
        }
    }
    if(ans==1 && b)
    {
        cout << "Elephant" << endl;
    }
    else if(ans==2 && b)
    {
        cout << "Bear" << endl;
    }
    else
    {
        cout << "Alien" << endl;
    }

    return 0;
}