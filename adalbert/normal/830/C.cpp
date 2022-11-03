#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <memory.h>
#include <string.h>
#include <complex>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".sol","r",stdin); freopen (name".dat","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define time pdojegoritg
#define int ll
typedef long long ll;
typedef long double ld;
const int arr=4*1e5;
const int md=1e9+7;

int a[arr];

signed main()
{
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        k+=a[i];
    }

    set<int> setik;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j*j<=a[i];j++)
        {
            setik.insert(j);
            setik.insert(a[i]/j+(a[i]%j!=0));
        }
    }
    vector<int> vec;
    for (auto i:setik)
    {
        vec.pb(i);
    }

    vec.pb(1e18);

    int ans=0;
    for (int i=0;i<vec.size()-1;i++)
    {
        int l=vec[i];
        int r=vec[i+1]-1;

        int sum=0;
        for (int j=1;j<=n;j++)
            sum+=a[j]/l+(a[j]%l!=0);

        int d=k/sum;
        d=min(d,r);

        if (d<l) continue;
        ans=max(ans,d);
    }

    cout<<ans;
}