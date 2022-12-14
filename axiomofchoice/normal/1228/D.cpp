#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<ll,ll>
set<pii> edge;
ll x,y,n,m;
bool tox,toy;
int co[100010];
vector<int> c1,c2,c3;
bool pd(){/*
	repeat(i,0,c1.size())
	repeat(j,0,c1.size())
		if(edge.count((pii){c1[i],c1[j]}))return false;
	repeat(i,0,c2.size())
	repeat(j,0,c2.size())
		if(edge.count((pii){c2[i],c2[j]}))return false;
	repeat(i,0,c3.size())
	repeat(j,0,c3.size())
		if(edge.count((pii){c3[i],c3[j]}))return false;*/
	repeat(i,0,c1.size())
	repeat(j,0,c2.size())
		if(!edge.count((pii){c1[i],c2[j]}))return false;
	repeat(i,0,c1.size())
	repeat(j,0,c3.size())
		if(!edge.count((pii){c1[i],c3[j]}))return false;
	repeat(i,0,c2.size())
	repeat(j,0,c3.size())
		if(!edge.count((pii){c2[i],c3[j]}))return false;
	return true;
}
int main(){
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;
	if(m==0){
		cout<<-1<<endl;
		return 0;
	}
	repeat(i,0,m){
		cin>>x>>y;x--,y--;
		edge.insert((pii) {x,y});
		edge.insert((pii) {y,x});
	}
	co[x]=1,c1.push_back(x);
	co[y]=2,c2.push_back(y);
	bool f=true;
	repeat(i,0,n)
	if(i!=x && i!=y){
		tox=edge.count((pii){i,x});
		toy=edge.count((pii){i,y});
		if(tox && toy)
			co[i]=3,c3.push_back(i);
		else if(!tox && toy)co[i]=1,c1.push_back(i);
		else if(!toy && tox)co[i]=2,c2.push_back(i);
		else f=false;
	}
	if(c1.empty() || c2.empty() || c3.empty()) f=false;
	if((ll)c1.size()*c2.size()
	+(ll)c2.size()*c3.size()
	+(ll)c1.size()*c3.size()!=m)f=false;
	
	if(f)f=pd();
	if(f){
		repeat(i,0,n)cout<<co[i]<<' ';
		cout<<endl;
	}
	else cout<<-1<<endl;
	return 0;
}