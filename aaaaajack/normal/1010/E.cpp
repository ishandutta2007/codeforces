#include<bits/stdc++.h>
#define N 200100
#define all(x) begin(x),end(x)
using namespace std;
struct point{
	int x[3];
}p[N];
bool cmpforward(int i,int j){
	return p[i].x[0]<p[j].x[0]||p[i].x[0]==p[j].x[0]&&i<j;
}
bool cmpbackward(int i,int j){
	return p[i].x[0]>p[j].x[0]||p[i].x[0]==p[j].x[0]&&i<j;
}
int ans[N];
// all points are turned into [0,n)^3
void build1d(vector<int>& points, vector<int>& seg){
	sort(all(points));
	points.resize(unique(all(points))-begin(points));
	int n=points.size();
	seg.resize(n*2,0);
}
void build2d(vector<pair<int,int>>& in,vector<vector<int>>& points,vector<vector<int>>& seg){
	sort(all(in));
	int m=in.back().first+1;
	points.assign(m*2,vector<int>());
	seg.assign(m*2,vector<int>());
	auto it=in.begin();
	for(int i=0;i<m;i++){
		while(it!=in.end() && it->first==i){
			points[m+i].push_back(it->second);
			++it;
		}
		build1d(points[m+i],seg[m+i]);
	}
	for(int i=m-1;i>0;i--){
		for(int j=0;j<2;j++){
			for(auto p:points[i*2+j]){
				points[i].push_back(p);
			}
		}
		build1d(points[i],seg[i]);
	}
}
int qry1d(vector<int>& points, vector<int>& seg, int y1, int y2){
	int n=points.size();
	y1=lower_bound(all(points),y1)-begin(points);
	y2=upper_bound(all(points),y2)-begin(points);
	y1+=n;
	y2+=n;
	int sum=0;
	while(y1<y2){
		if(y1&1) sum+=seg[y1++];
		if(y2&1) sum+=seg[--y2];
		y1>>=1,y2>>=1;
	}
	return sum;
}
int qry2d(vector<vector<int>>& points, vector<vector<int>>& seg, int x1,int x2, int y1, int y2){
	int n=points.size()/2;
	x1+=n;
	x2+=n+1;
	assert(x1<points.size() && x2<=points.size());
	int sum=0;
	while(x1<x2){
		if(x1&1){
			sum+=qry1d(points[x1],seg[x1],y1,y2); 
			x1++;
		}
		if(x2&1){
			--x2;
			sum+=qry1d(points[x2],seg[x2],y1,y2);
		}
		x1>>=1,x2>>=1;
	}
	return sum;
}
void upd1d(vector<int>& points, vector<int>& seg, int y, int z){
	int n=points.size();
	y=lower_bound(all(points),y)-begin(points);
	y+=n;
	while(y){
		seg[y]+=z;
		y>>=1;
	}
}
void upd2d(vector<vector<int>>& points, vector<vector<int>>& seg, int x, int y, int z){
	int n=points.size()/2;
	x+=n;
	while(x){
		upd1d(points[x],seg[x],y,z);
		x>>=1;
	}
}
int main(){
	const int inf=1e9+10000;
	int l[3],r[3],tx,ty,tz;
	for(int i=0;i<3;i++){
		l[i]=inf;
		r[i]=-inf;
	}
	int n,m,k,x[3];
	bool fail=false;
	vector<int> v[3];
	vector<int> check;
	scanf("%d%d%d",&tx,&ty,&tz);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&x[j]);
			l[j]=min(l[j],x[j]);
			r[j]=max(r[j],x[j]);
		}
	}
	for(int i=0;i<m+k;i++){
		bool in=true;
		for(int j=0;j<3;j++){
			scanf("%d",&p[i].x[j]);
			if(p[i].x[j]>r[j] || p[i].x[j]<l[j]) in=false;
			else p[i].x[j]=l[j];
			v[j].push_back(p[i].x[j]);
		}
		if(in){
			if(i<m) fail=true;
			else ans[i-m]=1;
		}
		else check.push_back(i);
	}
	for(int i=0;i<3;i++){
		v[i].push_back(l[i]);
		sort(v[i].begin(),v[i].end());
		v[i].resize(unique(all(v[i]))-begin(v[i]));
		l[i]=lower_bound(all(v[i]),l[i])-begin(v[i]);
	}
	vector<pair<int,int>> in;
	vector<vector<int>> points,seg;
	for(int i=0;i<m+k;i++){
		for(int j=0;j<3;j++){
			p[i].x[j]=lower_bound(all(v[j]),p[i].x[j])-begin(v[j]);
		}
		in.push_back(make_pair(p[i].x[1],p[i].x[2]));
	}
	in.push_back(make_pair(l[1],l[2]));
	build2d(in,points,seg);
	sort(all(check),cmpforward);
	for(auto i:check){
		if(p[i].x[0]>=l[0]){
			if(i<m) upd2d(points,seg,p[i].x[1],p[i].x[2],1);
			else{
				int tl[3],tr[3];
				for(int j=1;j<3;j++){
					tl[j]=min(l[j],p[i].x[j]);
					tr[j]=max(l[j],p[i].x[j]);
				}
				if(qry2d(points,seg,tl[1],tr[1],tl[2],tr[2])){
					ans[i-m]=2;
				}
			}
		}
	}
	build2d(in,points,seg);
	sort(all(check),cmpbackward);
	for(auto i:check){
		if(p[i].x[0]<=l[0]){
			if(i<m) upd2d(points,seg,p[i].x[1],p[i].x[2],1);
			else{
				int tl[3],tr[3];
				for(int j=1;j<3;j++){
					tl[j]=min(l[j],p[i].x[j]);
					tr[j]=max(l[j],p[i].x[j]);
				}
				if(qry2d(points,seg,tl[1],tr[1],tl[2],tr[2])){
					ans[i-m]=2;
				}
			}
		}
	}
	if(fail) puts("INCORRECT");
	else{
		puts("CORRECT");
		for(int i=0;i<k;i++){
			if(ans[i]==2) puts("CLOSED");
			else if(ans[i]==1) puts("OPEN");
			else puts("UNKNOWN");
		}
	}
	return 0;
}