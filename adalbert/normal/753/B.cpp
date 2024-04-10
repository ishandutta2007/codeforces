#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define int ll
#define y1 humiuyn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
///-----------------------------------------------------------------------///
pair <int , int > ask(string st)
{
    cout<<st<<'\n';
    fflush(stdout);
    int a,b;
    cin>>a>>b;
    return(make_pair(a,b));
}
signed main()
{
    vector <int> vec;
    for (int i=0;i<10;i++)
    {
        string st="";
        st+=i+'0';
        st+=i+'0';
        st+=i+'0';
        st+=i+'0';
        pair <int, int > p;
        p=ask(st);
        if (p.fir+p.sec!=0) vec.pb(i);
    }
    string st="";
        st+=vec[0]+'0';
        st+=vec[1]+'0';
        st+=vec[2]+'0';
        st+=vec[3]+'0';
        pair <int, int > p;
        p=ask(st);
        if (p.fir==4) return(0);
    while (next_permutation(vec.begin(),vec.end()))
    {
        string st="";
        st+=vec[0]+'0';
        st+=vec[1]+'0';
        st+=vec[2]+'0';
        st+=vec[3]+'0';
        pair <int, int > p;
        p=ask(st);
        if (p.fir==4) break;
    }
}