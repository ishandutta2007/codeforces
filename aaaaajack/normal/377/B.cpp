#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct stu{
	int num;
	int able;
	int pay;
};
struct bug{
	int num;
	int cplx;
	bool operator<(const bug& k)const{return cplx<k.cplx;}
};
bool cmp_a(const stu& x,const stu& y){
	if(x.able<y.able) return true;
	else return false;
}
struct cmp_p{
	bool operator()(const stu& x,const stu& y)const{
		if(x.pay>y.pay) return true;
		else return false;
	}
};
vector<bug> a;
vector<stu> b;
bool check(int k,int n,int m,int p,vector<int>& ans){
	priority_queue<stu,vector<stu>,cmp_p> pq;
	int i,j=n,s=0,l;
	stu r;
	for(i=m;i>0;i-=k){
		for(;j>0&&b[j].able>=a[i].cplx;j--){
			pq.push(b[j]);
		}
		if(pq.empty()) return false;
		r=pq.top();
		pq.pop();
		s+=r.pay;
		if(s>p) return false;
		for(l=i;l>0&&l>(i-k);l--){
			ans[a[l].num]=r.num;
		}
	}
	if(s>p) return false;
	else return true;
}

int bs(int low,int high,int n,int m,int p,vector<int>& ans){
	if(low==high){
		if(check(low,n,m,p,ans)) return low;
		else return m+1;
	}
	int mid=(low+high)/2;
	if(check(mid,n,m,p,ans)) return bs(low,mid,n,m,p,ans);
	else return bs(mid+1,high,n,m,p,ans);
}
		
int main(){
	int i,j,m,n,s,t;
	scanf("%d %d %d",&n,&m,&s);
	a.resize(m+1);
	b.resize(n+1);
	vector<int> ans(m+1);
	for(i=1;i<=m;i++){
		scanf("%d",&a[i].cplx);
		a[i].num=i;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&b[i].able);
		b[i].num=i;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&b[i].pay);
	}
	sort(++a.begin(),a.end());
	sort(++b.begin(),b.end(),cmp_a);
	t=bs(1,m+1,n,m,s,ans);
	if(t==m+1){
		printf("NO\n");
	}
	else{
		printf("YES\n");
		for(i=1;i<m;i++){
			printf("%d ",ans[i]);
		}
		printf("%d\n",ans[m]);
	}
	return 0;
}