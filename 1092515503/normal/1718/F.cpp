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
const int BBB=42;
int n,m,C,q,num,pri[100100],a[100100];
vector<int>v[100100];
vector<pair<int,int> >u[100100];
void sieve(){
	for(int i=2;i<=m;i++){
		if(!pri[i])pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&i*pri[j]<=m;j++){
			pri[i*pri[j]]=true;
			if(!(i%pri[j]))break;
		}
	}
	for(int i=1;i<=pri[0];i++)for(int j=pri[i];j<=m;j+=pri[i])v[j].push_back(i);
}
int lb[1<<13],pc[1<<13],P;
int hs[100100],cnt;
int f[700][1<<13];
void func(int*F,int V){
	F[0]=V;
	for(int i=1;i<(1<<P);i++)F[i]=F[i^(i&-i)]/pri[lb[i]+1];
	for(int i=0;i<(1<<P);i++)if(pc[i]&1)F[i]=-F[i];
	for(int i=0;i<P;i++)for(int j=0;j<(1<<P);j++)if(j&(1<<i))F[j]+=F[j^(1<<i)];
}
int ans[100100],pos[100100];
int main(){
	scanf("%d%d%d%d",&n,&m,&C,&q),sieve();
	// for(int i=1;i<=tot;i++)printf("[%d,%d]",sml[i],sta[i]);puts("");
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1,l,r;i<=q;i++)scanf("%d%d",&l,&r),u[r].emplace_back(l,i);
	// for(P=0;P<=pri[0]&&pri[P+1]<=BBB;P++);
	P=min(pri[0],13);
	for(int i=1;i<(1<<P);i++)lb[i]=(i&1?0:lb[i>>1]+1),pc[i]=pc[i>>1]+(i&1);
	for(int l=1,r;l<=C;l=r+1){
		r=C/(C/l);
		++cnt;
		for(int i=l;i<=r;i++)hs[i]=cnt;
		func(f[cnt],C/l);
	}
	for(int i=1;i<=n;i++){
		for(auto x:v[a[i]])pos[x]=i;
		for(auto _:u[i]){
			int STA=0,l=_.first,res=0;
			for(int j=1;j<=P;j++)if(pos[j]>=l)STA|=1<<j-1;
			// printf("<%d:%d>\n",_.second,STA);
			res=f[hs[1]][STA];
			for(int j=P+1;j<=pri[0];j++)if(pos[j]>=l){
				res-=f[hs[pri[j]]][STA];
				for(int k=j+1;k<=pri[0]&&1ll*pri[j]*pri[k]<=C;k++)
					if(pos[k]>=l)res+=f[hs[pri[j]*pri[k]]][STA];
			}
			ans[_.second]=res;
		}
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}