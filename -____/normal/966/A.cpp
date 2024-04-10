//CF 966A
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 111111;
const int inf = 1e9;
int n,m,cl,l[N],ce,e[N],v,q;
int sx,sy,tx,ty;
int ab(int x){
	return max(x,-x);
}
int main()
{
	int i,j,s1,s2;
	scanf("%d%d%d%d%d",&n,&m,&cl,&ce,&v);
	for(i=0;i<cl;i=i+1)
		scanf("%d",l+i);
	for(i=0;i<ce;i=i+1)
		scanf("%d",e+i);
	sort(l,l+cl),sort(e,e+ce);
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
		if(sx==tx){
			printf("%d\n",ab(sy-ty));
			continue;
		}
		s1=inf;
		if(cl){
			j=lower_bound(l,l+cl,sy)-l;
			if(j<cl)
				s1=min(s1,ab(sy-l[j])+ab(ty-l[j]));
			if(j)
				j--;
			if(j<cl)
				s1=min(s1,ab(sy-l[j])+ab(ty-l[j]));
			j=lower_bound(l,l+cl,ty)-l;
			if(j<cl)
				s1=min(s1,ab(sy-l[j])+ab(ty-l[j]));
			if(j)
				j--;
			if(j<cl)
				s1=min(s1,ab(sy-l[j])+ab(ty-l[j]));
			s1+=ab(sx-tx);
		}
		s2=inf;
		if(ce){
			j=lower_bound(e,e+ce,sy)-e;
			if(j<ce)
				s2=min(s2,ab(sy-e[j])+ab(ty-e[j]));
			if(j)
				j--;
			if(j<ce)
				s2=min(s2,ab(sy-e[j])+ab(ty-e[j]));
			j=lower_bound(e,e+ce,ty)-e;
			if(j<ce)
				s2=min(s2,ab(sy-e[j])+ab(ty-e[j]));
			if(j)
				j--;
			if(j<ce)
				s2=min(s2,ab(sy-e[j])+ab(ty-e[j]));
			s2+=(ab(sx-tx)-1)/v+1;
		}
		printf("%d\n",min(s1,s2));
	}
	return 0;
}