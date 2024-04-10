#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e3+1;
int a[maxn],n,mark[maxn*maxn];

void read()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],mark[a[i]]=1;
}

int gcd(int t1,int t2)
{
    while (t2)
    {
        int r=t1%t2;
        t1=t2;
        t2=r;
    }
    return t1;
}

void process()
{
    int t=a[1];
    for (int i=2;i<=n;i++) t=gcd(t,a[i]);
    if (!mark[t])
    {
        cout<<-1;
        return;
    }
    cout<<2*n<<endl;
    for (int i=1;i<=n;i++) cout<<a[i]<<" "<<t<<" ";
}

int main()
{
    read();
    process();
    return 0;
}