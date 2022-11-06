#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define db double
#define ld long double
#define pii pair<int,int> 
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define fore(i,a) for(int i=0;i<a.size();++i) 
const int N=4005;
int n,m,l[N],s[N],c[N],f[N][N];
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&l[i]);
	rep(i,1,n)scanf("%d",&s[i]);
	rep(i,1,n+m)scanf("%d",&c[i]);
	memset(f,-0x3f,sizeof(f));
	rep(i,1,n+m)f[i][0]=0;
	per(i,n,1)
	{
		per(j,n,1)f[l[i]][j]=max(f[l[i]][j],f[l[i]][j-1]-s[i]+c[l[i]]);
		int t=n;
		rep(j,l[i],n+m)
		{
			rep(k,0,t)f[j+1][k/2]=max(f[j+1][k/2],f[j][k]+c[j+1]*(k/2));
			t/=2;
		}
	}
	printf("%d\n",f[n+m][0]);return 0;
}