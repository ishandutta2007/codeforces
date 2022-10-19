#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<pii,int>               piii;
typedef pair<pll,ll>                plll;
typedef pair<pdd,double>            pddd;
typedef pair<pld,ld>                pldd;
typedef vector<int>                 vi;
typedef vector<ll>                  vll;
typedef vector<double>              vd;
typedef vector<ld>                  vld;
typedef vector<pii>                 vpii;
typedef vector<pll>                 vpll;
typedef vector<pdd>                 vpdd;
typedef vector<pld>                 vpld;
typedef vector<piii>                vpiii;
typedef vector<plll>                vplll;
typedef vector<pddd>                vpddd;
typedef vector<pldd>                vpldd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define pb                          push_back
#define ppb                         pop_back
#define pf                          push_front
#define ppf                         pop_front
#define X                           first
#define Y                           second
#define M                           make_pair
#define endt                        '\t'
#define ends                        ' '

int main()
{
    int x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int t1=abs(x1-x2);
    int t2=abs(y1-y2);

    if(t1 && t2 && t1!=t2)
    {
        cout << -1;
    }
    else if(t1 && t2)
    {
        cout << x1 << ends << y2 << ends << x2 << ends << y1;
    }
    else if(x1==x2)
    {
        cout << x1+t2 << ends << y1 << ends << x2+t2 << ends << y2;
    }
    else if(y1==y2)
    {
        cout << x1 << ends << y1+t1 << ends << x2 << ends << y2+t1;
    }

    return 0;
}