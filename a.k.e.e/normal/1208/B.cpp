#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define x first
#define y second
void chkmax(int &x,int y){x<y?x=y:0;}
void chkmin(int &x,int y){x>y?x=y:0;}
const int MAXN=2005;

int n,a[MAXN];
unordered_set<int> vis;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int ans;
    cin>>n;ans=n-1;
    for(int i=1;i<=n;i++)
    	cin>>a[i];
    for(int i=0;i<=n;i++)
    {
    	if(i && vis.count(a[i]))break;
    	unordered_set<int> ccc;
    	if(i)vis.insert(a[i]);
    	chkmin(ans,n-i);
    	for(int j=n;j>i;j--)
    	{
    		if(vis.count(a[j]) || ccc.count(a[j]))break;
    		ccc.insert(a[j]);
    		chkmin(ans,j-i-1);
    	}
    }
    printf("%d\n",ans);
    return 0;
}