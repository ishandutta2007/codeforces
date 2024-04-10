#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const ll maxll=numeric_limits<ll>::max();
const int maxint=numeric_limits<int>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ll md=1e9+7;
const ld eps=1e-6;

///---program start---///

int main()
{
    int l=-2e9,r=2e9;
    int n;
    cin>>n;
    while (n--)
    {
        string type;
        char ans;
        int zn;
        cin>>type>>zn>>ans;
        if (type==">")
        {
            if (ans=='Y') l=max(l,zn+1);
            else r=min(r,zn);
        }
        elif (type==">=")
        {
            if (ans=='Y') l=max(l,zn);
            else r=min(r,zn-1);
        }
        elif (type=="<")
        {
            if (ans=='N') l=max(l,zn);
            else r=min(r,zn-1);
        }
        else
        {
            if (ans=='N') l=max(l,zn+1);
            else r=min(r,zn);
        }
    }
    if (l>r) return cout<<"Impossible", 0;
    cout<<l;
}