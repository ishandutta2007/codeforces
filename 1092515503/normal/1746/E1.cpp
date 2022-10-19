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
// map<int,vector<int> >mp;
bool check(int x){
	printf("! %d\n",x),fflush(stdout);
	char s[10];
	scanf("%s",s);
	return s[1]==')';
}
bool check(vector<int>v){
	printf("? %d",v.size());
	for(auto x:v)printf(" %d",x);puts("");
	fflush(stdout);
	char s[10];
	scanf("%s",s);
	return s[0]=='Y';
}
void solve(vector<int>v){
	if(v.size()<=2){for(auto i:v)if(check(i))break;return;}
	vector<int>a,b,c;
	int sz=v.size()/3;
	for(int i=0;i<sz;i++)a.push_back(v[i]);
	for(int i=sz;i<sz*2;i++)b.push_back(v[i]);
	for(int i=sz*2;i<v.size();i++)c.push_back(v[i]);
	v.clear();
	bool A=check(a);
	if(!A){
		A=check(a);
		if(!A){
			for(auto x:b)v.push_back(x);
			for(auto x:c)v.push_back(x);
			return solve(v);
		}
	}
	bool B=check(b);
	if(!B){
		for(auto x:a)v.push_back(x);
		for(auto x:c)v.push_back(x);
		return solve(v);
	}else{
		for(auto x:a)v.push_back(x);
		for(auto x:b)v.push_back(x);
		return solve(v);
	}
}
int n;
int main(){
	/*for(int i=1;i<8;i<<=1){
		int a=3,b=3,c=3;
		for(int j=0;j<(1<<3);j++)if((j&3)&&(j&6)){
			int u=i&1,v=i&2,w=i&4;
			if(!(j&1))u^=1;
			if(!(j&2))v^=2;
			if(!(j&4))w^=4;
			// printf("%d%d%d->%d%d%d\n",i&1,i&2,i&4,u,v,w);
			mp[u+v+w].push_back(i);
			a&=1<<u;
			b&=1<<v;
			c&=1<<w;
		}
	}
	for(auto x:mp)if(x.first&1){
		for(auto y:x.second)printf("%d ",y);puts("");
	}*/
	scanf("%d",&n);
	vector<int>v;
	for(int i=1;i<=n;i++)v.push_back(i);
	solve(v);
	return 0;
}