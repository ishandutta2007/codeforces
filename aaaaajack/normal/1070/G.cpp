#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int h[N],a[N],id[N];
int main(){
	int n,m,x,y;
	vector<int> vl,vr,red;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		h[x]=y;
		id[x]=i;
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int l=1,r=n,cl=0,cr=0;
	while(!h[l]) l++;
	while(!h[r]) r--;
	while(l<=n && cl+a[l]>=0){
		cl+=a[l];
		if(h[l]>cl){
			cl=h[l];
			vl.push_back(id[l]);
		}
		else if(h[l]) red.push_back(id[l]);
		l++;
	}
	--l;
	while(r>l && cr+a[r]>=0){
		cr+=a[r];
		if(h[r]>cr){
			cr=h[r];
			vr.push_back(id[r]);
		}
		else if(h[r]) red.push_back(id[r]);
		r--;
	}
	if(l>=r){
		printf("%d\n",l);
		reverse(vl.begin(),vl.end());
		reverse(vr.begin(),vr.end());
		for(auto x:vl) printf("%d ",x);
		for(auto x:vr) printf("%d ",x);
		for(auto x:red) printf("%d ",x);
		puts("");
	}
	else puts("-1");
	return 0;
}