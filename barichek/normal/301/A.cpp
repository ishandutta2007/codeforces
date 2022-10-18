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

int sum_abs(vi a)
{
    int res=0;
    for (auto i:a)
        res+=abs(i);
    return res;
}

int sum(vi a)
{
    int res=0;
    for (auto i:a)
        res+=i;
    return res;
}

bool com(int a,int b)
{
    return abs(a)<abs(b);
}

main()
{
    int n;
    cin>>n;
    vi a;
    a.resize(2*n-1);
    for (auto &i:a)
        cin>>i;
    int cnt_pl=0;
    int cnt_mi=0;
    int cnt_nul=0;
    for (auto i:a)
        if (i>0)
            cnt_pl++;
        elif (i<0)
            cnt_mi++;
        else
            cnt_nul++;
    if (cnt_mi%2==0||cnt_nul>0)
        return cout<<sum_abs(a), 0;
    while (cnt_mi>0)
        if (cnt_mi%n==0)
            return cout<<sum_abs(a), 0;
        else
            cnt_mi-=2;
    while (cnt_mi<2*n)
        if (cnt_mi%n==0)
            return cout<<sum_abs(a), 0;
        else
            cnt_mi+=2;
    int res=sum(a);
    sort(all(a),com);
    res=max(res,sum_abs(a)-2*abs(a.front()));
    cout<<res;
}