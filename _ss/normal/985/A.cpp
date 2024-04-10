#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+1;
int a[maxn],n;
int main()
{
    cin>>n;
    for (int i=1;i<=n/2;i++) cin>>a[i];
    int t1=0,t2=0;
    sort(a+1,a+n/2+1);
    for (int i=1;i<=n/2;i++) t1+=abs(i*2-1-a[i]),t2+=abs(i*2-a[i]);
    cout<<min(t1,t2);
    return 0;
}