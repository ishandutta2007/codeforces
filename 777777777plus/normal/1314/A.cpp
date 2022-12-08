#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n;
int a[N],t[N];
ll ans;
map<int,int>p;
queue<int>s[N];

bool cmp(int x,int y){
	return a[x]<a[y]||(a[x]==a[y]&&t[x]>t[y]);
}

struct nd{
	int a,t;
	friend bool operator < (nd a,nd b){
		return a.t<b.t;
	}
};

int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)cin>>t[i];
	for(int i=1,tot=0;i<=n;++i){
		if(!p[a[i]]){
			p[a[i]]=++tot;
		}
		s[p[a[i]]].push(t[i]);
	}
	for(auto it=p.begin();it!=p.end();++it){
		static priority_queue<nd>q;
		int LIM=2e9;
		auto jt=it;++jt;
		if(jt!=p.end())LIM=jt->first-1;
		int x=it->second;
		while(!s[x].empty()){
			nd t;
			t.a=it->first;
			t.t=s[x].front();
			q.push(t);
			s[x].pop();
		}
		for(int j=it->first;j<=LIM;++j){
			if(q.empty())break;
			ans+=1ll*(j-q.top().a)*q.top().t;
			q.pop();
		}
	}
	cout<<ans<<endl;
}