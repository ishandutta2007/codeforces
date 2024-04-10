#include <iostream>
#include <fstream>
#include <cstring>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn = 100050;
const int limit = 16;
const int h = 31;
int n;
int len[maxn];
ll ans,inc;
ll cost[maxn];
ll bef[maxn][30];
ull ha[maxn],mi[maxn];
int sum[30][maxn];
char s[maxn];
bool pef[maxn][limit+5];
//{{{sub
inline ull sub (int l,int r)
{	
	return ha[r]-ha[l-1]*mi[r-l+1];
}
//}}}
//{{{check
inline bool check (int l1,int r1,int l2,int r2)
{
	return sub(l1,r1)==sub(l2,r2);
}
//}}}
//{{{lcp
inline int lcp (int l1,int l2)
{
	int res=0;
	for (int i=limit;i>=0;--i){
		int le=res+len[i];
		if (l1+le<=n&&l2+le<=n&&check(l1,l1+le,l2,l2+le))	res+=len[i]+1;
	}
	return res;
}
//}}}
//{{{init
inline void init ()
{
	for (int i=1;i<=limit+1;++i)	len[i]=len[i-1]<<1|1;
	mi[0]=1,ans=n=strlen(s+1);
	for (int i=1;i<=n;++i){
		for (int j=1;j<=26;++j)
			sum[j][i]=sum[j][i-1]+(s[i]-'a'+1==j);
		pef[i][1]=true,mi[i]=mi[i-1]*h;
		ha[i]=ha[i-1]*h+s[i]-'a'+1;
	}
}
//}}}
//{{{get_pef
inline void get_pef()
{
	for (int i=2;len[i]<=n;++i)
		for (int l=1,r=len[i];r<=n;++l,++r){
			int mid=l+len[i-1],ch=s[mid]-'a'+1;
			if (sum[ch][r]-sum[ch][l-1]==1)	pef[l][i]=pef[l][i-1]&pef[mid+1][i-1]&check(l,mid-1,mid+1,r);
			ans+=1ll*pef[l][i]*len[i]*len[i];
		}
}
//}}}
//{{{get_cost
inline void get_cost ()
{
	for (int i=1;len[i]<=n;++i)
		for (int l=1,r=len[i];r<=n;++l,++r){
			cost[l]+=1ll*pef[l][i]*len[i]*len[i];
			cost[r+1]-=1ll*pef[l][i]*len[i]*len[i];
		}
	for (int i=1;i<=n;++i)	cost[i]+=cost[i-1];
}
//}}}
//{{{calc
inline void calc (int l1,int k)// from l1   len[k]
{
	if (k==1){
		for (int i=1;i<=26;++i)	++bef[l1][i];
		return;
	}
	int mid=l1+len[k-1],l2=mid+1;
	ll tmp=1ll*len[k]*len[k];
	if (pef[l1][k-1]&&pef[l2][k-1]&&check(l1,mid-1,l2,l2+len[k-1]-1)){
		for (int i=1;i<=26;++i)
			if (sum[i][l1-1]==sum[i][mid-1])	bef[mid][i]+=tmp;
		return;
	}

	int prf1=lcp(l1,l2);
	int m1=l1+prf1,m2=l2+prf1;
	int prf2=lcp(m1+1,m2+1);
	if (m1+1+prf2<mid)	return;
	if (pef[l1][k-1]&&sum[s[mid]-'a'+1][l1-1]==sum[s[mid]-'a'+1][mid-1])	bef[m2][s[m1]-'a'+1]+=tmp;
	if (pef[l2][k-1]&&sum[s[mid]-'a'+1][mid]==sum[s[mid]-'a'+1][l2+len[k-1]-1])	bef[m1][s[m2]-'a'+1]+=tmp;
}
//}}}
int main()
{
	// freopen("356E.in","r",stdin);
	// freopen("356E.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>(s+1);
	init();
	get_pef();
	get_cost();

	for (int i=1;i<=n;++i)
		for (int j=1;i+len[j]-1<=n;++j)
			calc(i,j);

	for (int i=1;i<=n;++i)
		for (int j=1;j<=26;++j)	
			inc=max(inc,bef[i][j]-cost[i]);

	cout<<ans+inc<<endl;
	return 0;
}