#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define x first
#define y second
void chkmax(int &x,int y){x<y?x=y:0;}
void chkmin(int &x,int y){x>y?x=y:0;}
const int MAXN=1005;

int n,a[MAXN][MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int cnt=0;
    cin>>n;n>>=2;
    for(int i=0;i<n;i++)
    	for(int j=0;j<n;j++)
    		for(int x=0;x<4;x++)
    			for(int y=0;y<4;y++)
    				a[i*4+x][j*4+y]=cnt++;
    n<<=2;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    		printf("%d ",a[i][j]);
    	printf("\n");
    }
    return 0;
}