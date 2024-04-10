#include<bits/stdc++.h>
#define N 2000
using namespace std;
bitset<N> a[N],t[N],r[N];
char s[N+10];
int in[N];
vector<int> g[N];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		reverse(s,s+n);
		a[i]=bitset<N>(s);
		t[i]=a[i];
		a[i].set(i);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[j][i]) a[j]|=a[i];
		}
	}
	memset(in,-1,sizeof(in));
	int cnt=0;
	for(int i=0;i<n;i++){
		if(in[i]<0){
			for(int j=0;j<n;j++){
				if(in[j]>=0) continue;
				if(a[i][j]&&a[j][i]){
					g[cnt].push_back(j);
					in[j]=cnt;
				}
			}
			cnt++;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(in[i]!=in[j]) t[i][j]=0;
			r[j][i]=t[i][j];
		}
	}
	if(cnt==1) puts("0 1");
	else{
		int cst=0,ced=0,cmid=0;
		for(int i=0;i<n;i++){
			int st=1,ed=1;
			for(int j=0;j<n;j++){
				if(in[j]!=in[i] && a[j][i]) st=0;
				if(in[j]!=in[i] && a[i][j]) ed=0;
			}
			if(st){
				bitset<N> tmp,to=r[i];
				while(!(tmp==to)){
					int x=(tmp^to)._Find_first();
					tmp.set(x);
					to|=t[x];
					to.reset(i);
				}
				if(tmp.any()&&tmp.count()+1==g[in[i]].size()) cst++;
			}
			else if(ed){
				bitset<N> tmp,to=t[i];
				while(!(tmp==to)){
					int x=(tmp^to)._Find_first();
					tmp.set(x);
					to|=r[x];
					to.reset(i);
				}
				if(tmp.any()&&tmp.count()+1==g[in[i]].size()) ced++;
			}
			else cmid++;
		}
		if(cst+ced+cmid) printf("%d %d\n",1,cst+ced+cmid);
		else{
			if(g[0].size()==1 || g[1].size()==1) puts("-1");
			else{
				int ans=2*g[0].size()*g[1].size();
				for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){
						
					}
				}
				printf("%d %d\n",2,ans);
			}
		}
	}
	return 0;
}