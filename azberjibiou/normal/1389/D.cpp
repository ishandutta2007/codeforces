#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define fir first
#define sec second
#define pii pair<int, int>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
using namespace std;
int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1 , 0};
const int mxN=301000;
const int mxM=2100000;
const ll MOD=1000000007;
const ll INF=2000000000000000000;
ll n, k, l1, l2, r1, r2;
int main()
{
    gibon
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        cin >> l1 >> r1 >> l2 >> r2;
        ll ans=INF;
        if(l1>l2)
        {
            swap(l1, l2);
            swap(r1, r2);
        }
        if(r1<=l2)
        {
            ll a1=r1-l1, a2=r2-l2, b=l2-r1;
            if(k>a1+a2+b)
            {
                ll l1;
                if(a1+a2+b==0)    l1=n;
                else   l1=min(n, (k-1)/(a1+a2+b));
                ans=min(ans, 2*k-(a1+a2)*l1);
            }
            if(k<=(a1+a2+b)*n)
            {
                ll l2=(k-1)/(a1+a2+b)+1;
                ans=min(ans, b*l2+k);
            }
        }
        else if(r2>=r1)
        {
            ll a1=l2-l1, b=r1-l2, a2=r2-r1;
            if(k<=b*n)  ans=0;
            else if(k<=(a1+a2+b)*n) ans=k-b*n;
            else    ans=(k-(a1+a2+b)*n)*2+(a1+a2)*n;
        }
        else
        {
            ll a1=l2-l1, b=r2-l2, a2=r1-r2;
            if(k<=b*n)  ans=0;
            else if(k<=(a1+a2+b)*n) ans=k-b*n;
            else    ans=(a1+a2)*n+(k-(a1+a2+b)*n)*2;
        }
        cout << ans << '\n';
    }
}