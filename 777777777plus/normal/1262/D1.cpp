#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n,m,a[N],id[N],ans[N];
struct nd{
	int p,id;
	nd(int _p=0,int _id=0){
		p=_p;id=_id;
	}
};
vector<nd>q[N];

bool cmp(int x,int y){
	return a[x]>a[y];
}

struct ST{
	int tot=0; 
	int ls[N<<1],rs[N<<1],w[N<<1];
	int build(int l,int r){
		int x=++tot;
		if(l==r)return x;
		int mid=l+r>>1;
		ls[x]=build(l,mid);
		rs[x]=build(mid+1,r);
		return x;
	}
	void insert(int x,int l,int r,int p){
		if(l==r){
			w[x]=1;
			return;
		}
		int mid=l+r>>1;
		if(p<=mid)insert(ls[x],l,mid,p);
		else insert(rs[x],mid+1,r,p);
		w[x]=w[ls[x]]+w[rs[x]];
	}
	int ask(int x,int l,int r,int p){
		if(l==r)return l;
		int mid=l+r>>1;
		if(p<=w[ls[x]])return ask(ls[x],l,mid,p);
		return ask(rs[x],mid+1,r,p-w[ls[x]]);
	}
	void init(){
		for(int i=1;i<=tot;++i)ls[i]=rs[i]=w[i]=0;
		tot=0;
		int root=build(1,n);
	}
}T;

int main(){
	scanf("%d",&n);
	T.init();
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		id[i]=i;
	}
	sort(id+1,id+n+1,cmp);
	scanf("%d",&m);
	for(int i=1,k,p;i<=m;++i){
		scanf("%d%d",&k,&p);
		q[k].push_back(nd(p,i));
	}
	for(int i=1,r=1;i<=n;i=++r){
		while(r<n&&a[id[r+1]]==a[id[r]])r++;
		static vector<int>s;
		s.clear();
		for(int j=i;j<=r;++j)s.push_back(id[j]);
		sort(s.begin(),s.end());
		for(int j=i;j<=r;++j){
			T.insert(1,1,n,s[j-i]);
			for(int k=0;k<q[j].size();++k){
				int p=q[j][k].p,id=q[j][k].id;
				ans[id]=a[T.ask(1,1,n,p)];
			}
		}
	}
	for(int i=1;i<=m;++i)printf("%d\n",ans[i]);
}