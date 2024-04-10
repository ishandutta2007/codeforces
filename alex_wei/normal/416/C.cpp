#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
struct node{
	int c,p,pd;
	bool operator < (const node &v) const {
		return p>v.p;
	}
}e[1005],r[1005];
vector <node> q;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>e[i].c>>e[i].p,e[i].pd=i;
	sort(e+1,e+n+1);
	cin>>k;
	for(int i=1;i<=k;i++)cin>>r[i].p,r[i].c=i;
	sort(r+1,r+k+1);
	for(int i=1;i<=n;i++){
		int pos=0;
		for(int j=k;j>0;j--)
			if(e[i].c<=r[j].p&&!r[j].pd){
				pos=j;
				break;
			}
		if(pos)ans+=e[i].p,r[pos].pd=1,q.push_back({e[i].pd,r[pos].c,0});
	}
	cout<<q.size()<<" "<<ans<<endl;
	for(int i=0;i<q.size();i++)cout<<q[i].c<<" "<<q[i].p<<endl;
    return 0;
}