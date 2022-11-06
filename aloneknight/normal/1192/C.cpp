#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int P=998244353;
int m,n;ll ans=0,coef[2][2][2]={{{24,12},{12,4}},{{12,6},{4,1}}},g[66][66][66],h[11][66][66];
vector<string>v[11];
inline int gt(char c){return (c>='a')?(c-'a')*2:((c>='A')?(c-'A')*2+1:52+c-'0');}
int main()
{
	ios::sync_with_stdio(false);cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;cin>>s;
		v[s.size()].push_back(s);
		reverse(s.begin(),s.end());
		v[s.size()].push_back(s);
		for(auto t:s)m=max(m,gt(t)+1);
	}
	for(int i=3;i<=10;i++)
	{
		sort(v[i].begin(),v[i].end());
		v[i].erase(unique(v[i].begin(),v[i].end()),v[i].end());
		for(auto t:v[i])h[i][gt(t[0])][gt(t[i-1])]++;
		for(int p=0;p<m;p++)for(int q=p;q<m;q++)for(int r=q;r<m;r++)g[p][q][r]=0;
		for(int p=0;p<m;p++)for(int q=p;q<m;q++)for(int r=q;r<m;r++)for(int s=0;s<m;s++)g[p][q][r]=(g[p][q][r]+h[i][p][s]*h[i][q][s]*h[i][r][s])%P;
		for(int p=0;p<m;p++)for(int q=p;q<m;q++)for(int r=q;r<m;r++)for(int s=r;s<m;s++)ans=(ans+g[p][q][r]*g[p][q][s]%P*g[p][r][s]%P*g[q][r][s]%P*coef[p==q][q==r][r==s])%P;
	}
	printf("%lld\n",ans);
	return 0;
}