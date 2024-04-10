#include <bits/stdc++.h>
using namespace std;
///----------------------defines-----------------------///
#define push_back pb
#define make_pair mp
typedef long long ll;
typedef long double ld;
///--------------------end_of _define------------------///
///----------------procedures_and_functions------------///

///---------------------program_start-------------------///
int main()
{
    ll b=0,d=0,l=0;
    cin>>b>>d>>l;
    ll m=max(b,max(d,l));
    if (b<m) b++;
    if (d<m) d++;
    if (l<m) l++;
    //cout<<b<<' '<<d<<' '<<m<<'\n';
    cout<<max((ll)0,m-b)+max((ll)0,m-d)+max((ll)0,m-l);
}