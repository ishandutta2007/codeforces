#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN=200005;

int n;
ll a[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>n;
    if(!(n&1))return 0*printf("NO\n");
    printf("YES\n");
    int cur=1;
    for(int i=1;i<=n;i++)
    {
    	if(i&1){a[i]=cur,a[i+n]=cur+1;cur=2*n+1-cur;}
    	else {a[i]=cur;a[i+n]=cur-1;cur=2*n+3-cur;}
    }
    for(int i=1;i<=2*n;i++)
    	cout<<a[i]<<" ";
    return 0;
}