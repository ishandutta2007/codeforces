#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define time pdojegoritg
#define int ll
typedef long long ll;
typedef long double ld;
const int arr=500000;

int a[arr];

bool good(int u)
{
    int sc=sqrt(u);
    //cout<<sc<<'\n';
    return(sc*sc==u);
}

int get1(int u)
{
    int res=0;
    while (good(u+res))
        res++;
    return(res);
}

int get2(int u)
{
    int sc=sqrt(u);
    return(min(abs(u-sc*sc),abs(u-(sc+1)*(sc+1))));
}

bool check(pair<int,int> p1, pair<int,int> p2)
{
    return(p1.fir-p1.sec<p2.fir-p2.sec);
}

signed main()
{
    int a;
    cin>>a;
    int b=a;
    int c=a;
    while (b%10!=0)
        b++;
    while (c%10!=0)
        c--;
    if (abs(b-a)<abs(a-c))
        cout<<b; else
        cout<<c;
}