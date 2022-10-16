#include <bits/stdc++.h>
using namespace std;

const int N=1e3+5;

int cnt,ed[N<<5],son[N<<5][2];
string tmp;

bool find(string s,int len,int id){
	if(ed[id])return false;
	if(!len){
		ed[id]=1,tmp=s;
		return true;
	}
	if(!son[id][0])son[id][0]=++cnt;
	if(find(s+'0',len-1,son[id][0]))return true;
	if(!son[id][1])son[id][1]=++cnt;
	return find(s+'1',len-1,son[id][1]);
}

int n,a[N],b[N];
vector <string> ans[N];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(!find("",a[i],0))puts("NO"),exit(0);
		ans[a[i]].push_back(tmp);
	}
	puts("YES");
	for(int i=1;i<=n;i++){
		cout<<ans[b[i]].back()<<endl;
		ans[b[i]].pop_back();
	}
    return 0;
}