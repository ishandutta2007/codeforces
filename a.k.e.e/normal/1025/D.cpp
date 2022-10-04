#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
const int MAXN=705;

int n,a[MAXN];
bool ok[MAXN][MAXN];
bool L[MAXN][MAXN],R[MAXN][MAXN],f[MAXN][MAXN];

int gcd(int x,int y)
	{return y?gcd(y,x%y):x;}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    	scanf("%d",&a[i]);
    for(int i=0;i<=n;i++)
    	for(int j=0;j<=n;j++)
    	{
    		if(gcd(a[i],a[j])>1)ok[i][j]=1;
    		if(i>=j)L[i][j]=R[i][j]=1;
    	}
    for(int d=2;d<=n;d++)
    	for(int i=1,j;i+d-1<=n;i++)
    	{
    		j=i+d-1;
    		for(int k=i;k<j;k++)
    			if(ok[j][k])
    				L[i][j]|=(L[i][k]&&R[k][j-1]);
    		for(int k=j;k>i;k--)
    			if(ok[i][k])
    				R[i][j]|=(L[i+1][k]&&R[k][j]); 
    	}
    for(int i=1;i<=n;i++)
    	if(L[1][i]&&R[i][n])return 0*printf("Yes\n");
    return 0*printf("No\n");
}