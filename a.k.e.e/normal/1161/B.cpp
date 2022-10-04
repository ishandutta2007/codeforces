#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define x first
#define y second
const int MAXN=200005;

int n,m;
pii a[MAXN],b[MAXN];
pii mp(int x,int y){return x<y?make_pair(x,y):make_pair(y,x);}
bool notp[MAXN];
int prm[MAXN],pn;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int x,y;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
    	scanf("%d%d",&a[i].x,&a[i].y);
    	a[i].x%=n;a[i].y%=n;
    	if(a[i].x>a[i].y)swap(a[i].x,a[i].y);
    }
    sort(a+1,a+m+1);
    /*for(int i=1;i<=m;i++)
    	cout<<a[i].x<<" "<<a[i].y<<endl;*/
    
    notp[0]=notp[1]=1;
    for(int i=2;i<=n;i++)
    {
    	if(!notp[i])prm[++pn]=i;
    	for(int j=1;j<=pn && prm[j]*i<=n;j++)
    	{
    		notp[prm[j]*i]=1;
    		if(!(i%prm[j]))break;
    	}
    }
    
    for(int i=1;i<=pn;i++)
    {
    	if(n%prm[i])continue;
    	int t=n/prm[i];
    	for(int j=1;j<=m;j++)
    		b[j]=mp((a[j].x+t)%n,(a[j].y+t)%n);
    	sort(b+1,b+m+1);
		bool flag=1;
    	for(int j=1;j<=m;j++)
    		if(a[j]!=b[j]){flag=0;break;}
    	if(flag)return 0*printf("Yes\n");
    }
    printf("No\n");
    return 0;
}