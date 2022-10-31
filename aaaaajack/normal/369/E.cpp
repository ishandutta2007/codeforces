#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#define len 1000010
using namespace std;
int fen[len]={0};
struct seg{
	int l,r,p;
	bool operator<(const seg& k)const{return l>k.l||((l==k.l)&&(r<k.r))||((l==k.l)&&(r==k.r)&&(p<k.p));}
};
void add(int x){
	while(x<len){
		fen[x]++;
		x+=x&(-x);
	}
}
int sum(int x){
	int ans=0;
	while(x>0){
		ans+=fen[x];
		x-=x&(-x);
	}
	return ans;
}
int main(){
	vector<seg> a;
	vector<int> ans;
	int n,m,l,r,i,s;
	seg temp;
	scanf("%d %d",&n,&m);
	a.resize(n);
	ans.resize(m+1,n);
	for(i=1;i<=n;i++){
		scanf("%d %d",&l,&r);
		a[i-1].l=l;
		a[i-1].r=r;
	}
	for(i=1;i<=m;i++){
		scanf("%d",&s);
		l=1;
		for(;s--;l=r+1){
			scanf("%d",&r);
			if(r>l){
				temp.l=l;
				temp.r=r-1;
				temp.p=i;
				a.push_back(temp);
			}
		}
		if(len>l){
			temp.l=l;
			temp.r=len-1;
			temp.p=i;
			a.push_back(temp);
		}
	}
	sort(a.begin(),a.end());
	for(i=0;i<a.size();i++){
		if(a[i].p){
			ans[a[i].p]-=sum(a[i].r);
		}
		else{
			add(a[i].r);
		}
	}
	for(i=1;i<=m;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}