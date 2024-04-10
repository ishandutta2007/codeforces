#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
map<pair<int,int>,bool>mp;
map<int,int>X,Y;
set<tuple<int,int,int> >s;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x,&y),mp[make_pair(x,y)]=true;
		if(X.find(x)==X.end())X[x]=y;else X[x]=min(X[x],y);
		if(Y.find(y)==Y.end())Y[y]=x;else Y[y]=min(Y[y],x);
	}
	x=y=0;
	for(auto i=X.begin(),j=Y.begin();i!=X.end()||j!=Y.end();){
		while(i!=X.end()&&i->first<x)i++;
		while(j!=Y.end()&&j->first<y)j++;
		int xx=0x3f3f3f3f,yy=0x3f3f3f3f;
		if(i!=X.end())xx=i->first;
		if(j!=Y.end())yy=j->first;
		int mn=min(xx-x,yy-y);
		bool xxx=false,yyy=false;
		if(x+mn==xx&&i->second<=y+mn)xxx=true;
		if(y+mn==yy&&j->second<=x+mn)yyy=true;
//		printf("(%d,%d)->(%d,%d):%d %d|%d,%d\n",x,y,x+mn,y+mn,xxx,yyy,xx,yy);
		if(mn+1-max(xxx,yyy))s.insert(make_tuple(x+mn-max(xxx,yyy),x,y));
		if(!max(xxx,yyy))xxx=yyy=true;
		x+=mn+xxx,y+=mn+yyy;
	}
	s.insert(make_tuple(0x3f3f3f3f,x,y));
//	for(auto i:s)printf("(%d,%d)(%d,%d)\n",get<1>(i),get<2>(i),get<0>(i),get<2>(i)+get<0>(i)-get<1>(i));
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(mp.find(make_pair(x,y))!=mp.end()){puts("LOSE");continue;}
		auto tmp=s.lower_bound(make_tuple(x,0,0));
		if(tmp==s.end()||get<1>(*tmp)>x){puts("WIN");continue;}
		puts(get<2>(*tmp)+x-get<1>(*tmp)==y?"LOSE":"WIN");
	}
	return 0;
}
/*
5 1
14 13
0 18
2 14
7 19
13 0

17 17
*/