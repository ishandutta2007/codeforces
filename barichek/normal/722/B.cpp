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

const int maxint=numeric_limits<int>::max();
const ll maxll=numeric_limits<ll>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ll md=1e9+7;
const ld eps=1e-10;

///---program start---///

main()
{
    set<char> setik;
    setik.insert('a');
    setik.insert('e');
    setik.insert('i');
    setik.insert('o');
    setik.insert('u');
    setik.insert('y');
    int n;
    cin>>n;
    vector<int> a;
    a.resize(n);
    for (int i=0;i<n;i++)
        cin>>a[i];
    getchar();
    bool ok=true;
    for (int i=0;i<n;i++)
    {
        string s;
        getline(cin,s);
        for (auto j:s)
            if (setik.count(j)) a[i]--;
        if (a[i]!=0) ok=false;
    }
    cout<<(ok?"YES":"NO");
}