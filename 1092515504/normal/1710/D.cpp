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
int T,n,X[2010],Y[2010],m;
char s[2010][2010];
int dsu[2010];
int find(int x){return dsu[x]==x?x:dsu[x]=find(dsu[x]);}
bool same(int x,int y){return find(x)==find(y);}
void merge(int x,int y){x=find(x),y=find(y);if(x!=y)dsu[x]=y;}
set<int>st;
void link(int x,int y){++m,X[m]=x,Y[m]=y;}
void mina(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+i);
	for(int i=1;i<=n;i++)dsu[i]=i,st.insert(i);
	for(int o=2;o<=n;o++)for(int i=1;i+o-1<=n;i++)if(s[i][i+o-1]=='1'&&!same(i,i+o-1)){
		vector<int>v;
		v.push_back(i),v.push_back(i+o-1);
		st.erase(find(i)),st.erase(find(i+o-1));
		v.push_back(i),v.push_back(i+o-1);
		for(auto it=st.lower_bound(i);it!=st.end()&&*it<=i+o-1;)
			v.push_back(*it),it=st.erase(it);
		sort(v.begin(),v.end());
		for(int j=1;j<v.size();j++)merge(v[0],v[j]);
		st.insert(find(i));
		merge(i,i+o-1);
		if(v.size()&1){
			int x=0,y=v.size()-1;
			link(v[x],v[v.size()>>1]);
			link(v[y],v[v.size()>>1]);
			for(x++,y--;x+1<y-1;x++,y--)
				link(v[x],v[y-1]),link(v[y],v[x+1]);
		}
		else{
			int x=0,y=v.size()-1;
			link(v[x],v[y]);
			for(x++,y--;x+1<y-1;x++,y--)
				link(v[x],v[y-1]),link(v[y],v[x+1]);
		}
	}
	st.clear();
	for(int i=1;i<=m;i++)printf("%d %d\n",X[i],Y[i]);
	m=0;
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}