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
int T,n,m,K;
vector<pair<int,long long> >u,v;
void mina(){
	scanf("%d%d",&n,&K),u.clear(),v.clear();
	for(int i=1,x,y;i<=n;i++){
		scanf("%d",&x),y=1;
		while(!(x%K))x/=K,y*=K;
		if(u.empty()||u.back().first!=x)u.emplace_back(x,y);
		else u.back().second+=y;
	}
	scanf("%d",&m);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d",&x),y=1;
		while(!(x%K))x/=K,y*=K;
		if(v.empty()||v.back().first!=x)v.emplace_back(x,y);
		else v.back().second+=y;
	}
	if(u.size()!=v.size()){puts("No");return;}
	for(int i=0;i<u.size();i++)if(u[i]!=v[i]){puts("No");return;}
	puts("Yes");
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}