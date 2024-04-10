#include <bits/stdc++.h>
using namespace std;

const int N=8;
const int c=255;

bool cmp(string a,string b){
	return a.size()!=b.size()?a.size()<b.size():a<b;
}

int n,vis[1<<N][3],x,y,z;
string s[1<<N][3];

struct node{
	string s;
	int val,sym;
	bool operator < (const node &v) const {
		return s.size()!=v.s.size()?s.size()>v.s.size():s>v.s;
	}
};
priority_queue <node> q;

void add(node x){
	if(!vis[x.val][x.sym]&&cmp(x.s,s[x.val][x.sym]))
		s[x.val][x.sym]=x.s,q.push(x);
}

int main(){
	string inf="";
	for(int i=1;i<=100;i++)inf+='z';
	for(int i=0;i<256;i++)for(int j=0;j<3;j++)s[i][j]=inf;
	
	x=15,y=51,z=85;
	q.push({s[x][2]="x",x,2});
	q.push({s[y][2]="y",y,2});
	q.push({s[z][2]="z",z,2});
	
	while(!q.empty()){
		node t=q.top(),w; q.pop();
		if(vis[t.val][t.sym])continue;
		vis[t.val][t.sym]=1;
		w=t; if(t.sym<2)w.s='('+w.s+')';
		add({'!'+w.s,c-w.val,1});
		for(int i=0;i<256;i++)
			for(int j=0;j<3;j++)
				if(vis[i][j]){
					string d=s[i][j],c=t.s;
					add({c+'|'+d,t.val|i,0}),add({d+'|'+c,t.val|i,0});
					if(!j)d='('+d+')'; if(!t.sym)c='('+c+')'; 
					add({c+'&'+d,t.val&i,1}),add({d+'&'+c,t.val&i,1});
				}
	}
	
	cin>>n;
	while(n--){
		string f,ans; int id=0; cin>>f;
		for(int i=0;i<8;i++)id+=(f[i]-'0')<<(7-i);
		ans=s[id][0];
		if(cmp(s[id][1],ans))ans=s[id][1];
		if(cmp(s[id][2],ans))ans=s[id][2];
		cout<<ans<<endl;
	}
	return 0;
}