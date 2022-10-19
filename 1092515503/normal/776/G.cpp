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
int q;
ll L,R,X,f[16][60][2][2],ans;
ll dfs(int cha,int pos,bool cur,bool occ,bool lim){
	if(pos==-1)return occ;
	if(!lim&&f[cha][pos][cur][occ]!=-1)return f[cha][pos][cur][occ];
	ll res=0;
	for(int i=0;i<=(lim?((X>>pos)&1):1);i++){
		if(pos==cha&&i==0)continue;
		bool CUR=cur&&(i==((cha>>(pos&3))&1));
		if(cur&&!CUR&&i)continue;
		bool OCC=occ||(!(pos&3)&&CUR);
		if(!(pos&3))CUR=true;
		res+=dfs(cha,pos-1,CUR,OCC,lim&&(i==((X>>pos)&1)));
	}
	// if(res)printf("%d,%d,%d,%d,%d:%d\n",cha,pos,cur,occ,lim,res);
	if(!lim)f[cha][pos][cur][occ]=res;
	return res;
}
void mina(){
	scanf("%llx%llx",&L,&R);if(L)L--;ans=0;
	X=R;for(int i=1;i<16;i++)ans+=dfs(i,59,true,false,true);
	X=L;for(int i=1;i<16;i++)ans-=dfs(i,59,true,false,true);
	printf("%lld\n",ans);
}
int main(){
	memset(f,-1,sizeof(f));
	scanf("%d",&q);
	while(q--)mina();
	return 0;
}
/*
1
1 f
*/