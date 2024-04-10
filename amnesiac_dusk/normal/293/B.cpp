/*
 * Words like "tomorrow" or "future" or "fate"
 *		No matter how far they extend their hands
 *			We breathe, we dream, we raise our love
 *				In a timeless land that is far out of reach
 */
#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#ifndef rd
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
#define double long double
#define pii pair<int,int>
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(x) x.begin(),x.end()
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

int ans=0;
int n,m,k;
int aa[15][15],a[15][15];
int fact[1001],invfact[1001];
bool te[15][15][11];
bool temp[15][15][11];
int tempola[15];
void generate(int rown,int coln)
{
	if(rown==n)
	{
		for(int i=1; i<=k; i++)
		{
			te[rown][coln][i]=0;
			tempola[i]=0;
		}
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				te[rown][coln][a[i][j]]=1;
		int tolol=0;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(aa[i][j])
				{
					if(tempola[aa[i][j]]&&tempola[aa[i][j]]!=a[i][j])
						return;
					if(te[rown][coln][a[i][j]])
						tolol++;
					tempola[aa[i][j]]=a[i][j];
					te[rown][coln][a[i][j]]=0;
				}
		for(int i=1; i<=k; i++)
			tempola[i]=0;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(aa[i][j])
				{
					if(tempola[a[i][j]]&&tempola[a[i][j]]!=aa[i][j])
						return;
					if(te[rown][coln][a[i][j]])
						tolol++;
					tempola[a[i][j]]=aa[i][j];
					te[rown][coln][a[i][j]]=0;
				}
		int lolol=0;
		for(int i=1; i<=k; i++)
			lolol+=te[rown][coln][i];
		ans=(ans+(fact[k-tolol]*invfact[k-tolol-lolol]))%mod;
	}
	else
	{
		for(int i=1; i<=k; i++) {
			te[rown][coln][i]=0;
			temp[rown][coln][i]=0;
		}
		for(int i=0; i<=rown; i++)
			for(int j=0; j<=coln; j++)
				te[rown][coln][a[i][j]]=1;
		int mm=0;
		for(int i=0; i<rown; i++)
			for(int j=0; j<m; j++)
			{
				mm=max(a[i][j],mm);
				temp[rown][coln][a[i][j]]=1;
			}
		for(int j=0; j<coln; j++)
			mm=max(a[rown][j],mm);
		for(int i=1; i<=mm; i++)
			if((!te[rown][coln][i])&&temp[rown][coln][i])
			{
				a[rown][coln]=i;
				if(coln==m-1)
					generate(rown+1,0);
				else
					generate(rown,coln+1);
				a[rown][coln]=0;
			}
		a[rown][coln]=mm+1;
		if(mm<k){
			if(coln==m-1)
				generate(rown+1,0);
			else
				generate(rown,coln+1);
		}
		a[rown][coln]=0;
	}
}
signed main()
{
	IO;
	cin>>n>>m>>k;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>aa[i][j];
	fact[0]=1;
	for(int i=1; i<=1000; i++)
		fact[i]=(fact[i-1]*i)%mod;
	invfact[1000]=powm(fact[1000],mod-2,mod);
	for(int i=999; i>=0; i--)
		invfact[i]=(invfact[i+1]*(i+1))%mod;
	generate(0,0);
	cout<<ans<<endl;
}
ll powm(ll a,ll b, ll m)
{
	ll te=1;
	while(b)
	{
		if(b&1)
			te=(te*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return te;
}