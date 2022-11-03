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
#define time pdojegoritg
#define int ll
typedef long long ll;
typedef long double ld;
char a[500000];
signed main()
{
    string st1,st2;
    cin>>st1>>st2;
    int n=st1.size();
    sort(st1.begin(),st1.end());
    sort(st2.begin(),st2.end());
    reverse(st2.begin(),st2.end());
    while (st1.size()>(n+1)/2) st1.pop_back();
    while (st2.size()>(n)/2) st2.pop_back();
    int s1=0;
    int s2=0;
    int f1=st1.size()-1;
    int f2=st2.size()-1;
    int s=0;
    int f=n-1;
    for (int i=1;i<=n;i++)
        if (i%2==1)
        {
            if (st1[s1]>=st2[s2])
            {
                a[f]=st1[f1];
                f1--;
                f--;
            } else
            {
                a[s]=st1[s1];
                s1++;
                s++;
            }
        } else
        {
            if (st1[s1]>=st2[s2])
            {
                a[f]=st2[f2];
                f2--;
                f--;
            } else
            {
                a[s]=st2[s2];
                s2++;
                s++;
            }
        }
    for (int i=0;i<n;i++)
        cout<<a[i];
}