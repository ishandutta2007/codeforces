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
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int arr=1600;
const int md=1e9+7;

int a[500000];

signed main()
{
    int n,cnt1,cnt2;
    cin>>n>>cnt1>>cnt2;
    int cc1=cnt1;
    int cc2=cnt2;
    string st;
    cin>>st;
    for (int i=0;i<n;i++)
    {
        if (st[i]=='*')
            continue;
        if ((i-1<0 || st[i-1]!='q') && cnt1>cnt2 && cnt1!=0)
        {
            st[i]='q';
            cnt1--;
        } else
        if ((i-1<0 || st[i-1]!='w') && cnt2>cnt1 && cnt2!=0)
        {
            st[i]='w';
            cnt2--;
        } else
        if ((i-1<0 || st[i-1]!='q') && cnt1!=0)
        {
            st[i]='q';
            cnt1--;
        } else
        if ((i-1<0 || st[i-1]!='w') && cnt2!=0)
        {
            st[i]='w';
            cnt2--;
        }
    }

    cout<<cc1+cc2-cnt1-cnt2;
}