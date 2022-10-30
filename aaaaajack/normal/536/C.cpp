#include<cstdio>
#include<utility>
#include<algorithm>
#include<set>
#define point pair<long long,long long> 
#define x first
#define y second
#define N 200100
using namespace std;
point p[N],v[N];
int sp,id[N];
bool cross(point a,point b,point c){
	return (a.x-b.x)*(a.y-c.y)*c.x*b.y-(a.x-c.x)*(a.y-b.y)*b.x*c.y>=0; 
}
bool cmp(int i,int j){
	return p[i]<p[j];
}
bool check(point a,point b,point c){
	if(a.x>=b.x&&a.y>=b.y||c.x>=b.x&&c.y>=b.y) return false;
	if(a.x<b.x&&a.y>b.y&&c.x>b.x&&c.y<b.y) return false;
	return true;
}
int main(){
	int n,i;
	set<point> ans;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%I64d%I64d",&p[i].x,&p[i].y);
		id[i]=i;
	}
	sort(id,id+n,cmp);
	for(i=0;i<n;i++){
		if(sp&&p[id[i]]==v[sp-1]) continue;
		while(sp>=2&&!cross(v[sp-2],v[sp-1],p[id[i]])) sp--;
		v[sp++]=p[id[i]];
	}
	for(i=n-1;i>=0;i--){
		if(sp&&p[id[i]]==v[sp-1]) continue;
		while(sp>=2&&!cross(v[sp-2],v[sp-1],p[id[i]])) sp--;
		v[sp++]=p[id[i]];
	}
	if(sp==1){
		for(i=1;i<=n;i++) printf("%d ",i);
	}
	else{
		v[sp++]=v[1];
		for(i=1;i<sp-1;i++){
			if(check(v[i-1],v[i],v[i+1])) ans.insert(v[i]);
		}
		for(i=0;i<n;i++){
			if(ans.count(p[i])) printf("%d ",i+1);
		}
	}
	putchar('\n');
}