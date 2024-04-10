#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+1;
int n;

int ask(int st)
{
    cout<<"? "<<st<<endl;
    fflush(stdout);
    int ans;
    cin>>ans;
    return ans;
}

int f(int st)
{
    int a=ask(st),b=ask(((st+n/2-1)%n)+1);
    return (b-a+n/2)/2;
}

int main()
{
    cin>>n;
    if (n%4!=0) cout<<"! "<<-1,exit(0);
    int l=1,r=n,mid,k;
    while (l<=r)
    {
        mid=(l+r)/2;
        k=f(mid);
        if (k==n/4)
        {
            cout<<"! "<<mid;
            break;
        }
        if (k<n/4) l=mid+1; else r=mid-1;
    }
    return 0;
}