#include<bits/stdc++.h>
#define N 2010
using namespace std;
struct point{
	int x,y;
	int id;
	point(){}
	point(int _x,int _y,int _i=0):x(_x),y(_y),id(_i){}
	point operator-(point r)const{
		return point(x-r.x,y-r.y);
	}
	long long operator*(point r)const{
		return 1LL*x*r.y-1LL*y*r.x;
	}
	bool operator<(point r)const{
		if(x<r.x) return true;
		if(x==r.x&&y<r.y) return true;
		return false;
	}
}p[N];
int f[N],a[N],sz[N];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
bool uni(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		f[fx]=fy;
		sz[fy]+=sz[fx];
		return true;
	}
	else return false;
}
point ori;
bool cmp(point a,point b){
	return (a-ori)*(b-ori)>0;
}
int main(){
	vector<point> v;
	vector<pair<int,int>> ans;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		p[i]=point(x,y,i);
		a[i]=z;
		f[i]=i;
		sz[i]=1;
	}
	for(int i=1;i<=n;i++){
		uni(i,a[i]);
	}
	for(int i=1;i<=n;i++){
		if(f[i]!=i || sz[i]!=1){
			v.push_back(p[i]);
		}
	}
	if(!v.empty()){
		sort(v.begin(),v.end());
		ori=v[0];
		sort(v.begin()+1,v.end(),cmp);
		for(int i=2;i<v.size();i++){
			if(uni(v[i-1].id,v[i].id)){
				ans.push_back(make_pair(v[i-1].id,v[i].id));
				swap(a[v[i-1].id],a[v[i].id]);
			}
		}
		while(a[ori.id]!=ori.id){
			int nxt=a[ori.id];
			swap(a[ori.id],a[nxt]);
			ans.push_back(make_pair(ori.id,nxt));
		}
	}
	printf("%d\n",(int)ans.size());
	for(int i=0;i<ans.size();i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}