#include <bits/stdc++.h>
#define ll long long

using namespace std;
string s1;
ll sc,a[200001],sm,t,x,s,mj,j,n,i,k,scc,r,l;
int main() {

    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k ;
    for(i=0;i<n;i++)cin >> a[i];
    for(i=0;i<k;i++)t+=a[i];
    l=0;r=k;
    sc=t;
    scc=1;
    while(r<n)
    {
        t-=a[l];
        l++;
        t+=a[r];
        sc+=t;
        scc++;
        r++;
    }
    double ss=sc,sss=scc;
    double dd;
    dd=ss/sss;
    cout << fixed << setprecision(9) << dd << endl;
    return 0;
}