/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int f[300100],nex[3][300100];
ll s[2][300100];
map<ll,int>mp[3];
struct dat{int i,j,val;dat(int I,int J,int V){i=I,j=J,val=V;}};
vector<dat>v[300100];
void chmx(int&x,int y){if(x<y)x=y;}
void chmn(int&x,int y){if(x>y)x=y;}
void consi(int i,int j,int val){chmx(f[max(i,j)],val),v[min(i,j)].emplace_back(i,j,val);}
void trans(int i,int j,int val){
	if(i<n){consi(i+1,j,val);if(nex[0][i]!=-1)consi(nex[0][i],j,val+1);}
	if(j<n){consi(i,j+1,val);if(nex[1][j]!=-1)consi(i,nex[1][j],val+1);}
	if(i==j&&nex[2][i]!=-1)consi(nex[2][i],nex[2][j],val+1);
}
int main(){
	scanf("%d",&n);
	for(int _=0;_<2;_++)for(int i=1;i<=n;i++)scanf("%lld",&s[_][i]),s[_][i]+=s[_][i-1];
	mp[0][0]=mp[1][0]=mp[2][0]=0;
	memset(nex,-1,sizeof(nex));
	for(int i=1;i<=n;i++){
		// printf("<%d,%d,%d>\n",s[0][i],s[1][i],s[0][i]+s[1][i]);
		if(mp[0].find(s[0][i])!=mp[0].end())nex[0][mp[0][s[0][i]]]=i;mp[0][s[0][i]]=i;
		if(mp[1].find(s[1][i])!=mp[1].end())nex[1][mp[1][s[1][i]]]=i;mp[1][s[1][i]]=i;
		if(mp[2].find(s[0][i]+s[1][i])!=mp[2].end())nex[2][mp[2][s[0][i]+s[1][i]]]=i;mp[2][s[0][i]+s[1][i]]=i;
	}
	// for(int i=0;i<n;i++)printf("%d %d %d\n",nex[0][i],nex[1][i],nex[2][i]);
	for(int i=0;i<n;i++){
		// printf("%d\n",f[i]);
		trans(i,i,f[i]);
		int I=0x3f3f3f3f,J=0x3f3f3f3f;
		for(auto x:v[i]){
			// printf("%d:%d,%d:%d\n",i,x.i,x.j,x.val);
			if(x.i==i&&x.val==f[i]+1)chmn(J,x.j);
			if(x.j==i&&x.val==f[i]+1)chmn(I,x.i);
		}
		if(I<=n)trans(I,i,f[i]+1);
		if(J<=n)trans(i,J,f[i]+1);
	}
	printf("%d\n",f[n]);
	return 0;
}