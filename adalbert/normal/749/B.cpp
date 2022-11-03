#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);

///-----------------------------------------------------------------------///
int main()
{
    int x1,x2,x3,y1,y2,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    cout<<3<<'\n';
    cout<<x3-(x1-x2)<<' '<<y3-(y1-y2)<<'\n';
    swap(x3,x1);
    swap(y3,y1);
    cout<<x3-(x1-x2)<<' '<<y3-(y1-y2)<<'\n';
    swap(x3,x1);
    swap(y3,y1);
    swap(x2,x1);
    swap(y2,y1);
    cout<<x3-(x1-x2)<<' '<<y3-(y1-y2)<<'\n';
}