#include<bits/stdc++.h>
#define N 500100
using namespace std;
int l[N],r[N],id[N],ans[N];
int a[N];
vector<int> sg[N*2];
vector<int> g[N];
vector<int>::iterator cur[N];
void upd(int sl,int sr,int n,int v){
	sl+=n,sr+=n;
	while(sl<sr){
		if(sl&1) sg[sl++].push_back(v);
		if(sr&1) sg[--sr].push_back(v);
		sl>>=1,sr>>=1;
	}
}
int qry(int x,int n){
	x+=n;
	int res=0;
	while(x){
		while(!sg[x].empty() && sg[x].back()<*cur[a[sg[x].back()]]) sg[x].pop_back();
		if(!sg[x].empty()) res=a[sg[x].back()];
		x>>=1;
	}
	return res;
}
bool cmp(int i,int j){
	return l[i]<l[j];
}
int main(){
	int n,q;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		g[a[i]].push_back(i);
	}
	for(int i=0;i<N;i++){
		g[i].push_back(n);
		cur[i]=g[i].begin();
		if(cur[i]+1!=g[i].end()) upd(*cur[i],*(cur[i]+1),n,*cur[i]);
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d%d",&l[i],&r[i]);
		l[i]--,r[i]--;
		id[i]=i;
	}
	sort(id,id+q,cmp);
	int s=0;
	for(int i=0;i<n;i++){
		while(s<q && l[id[s]]<=i){
			ans[id[s]]=qry(r[id[s]],n);
			s++;
		}
		cur[a[i]]++;
		if(cur[a[i]]+1!=g[a[i]].end()) upd(*cur[a[i]],*(cur[a[i]]+1),n,*cur[a[i]]);
	}
	for(int i=0;i<q;i++) printf("%d\n",ans[i]);
	return 0;
}