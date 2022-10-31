#include<utility>
#include<cstdio>
#include<algorithm>
#include<vector>
#define N 200100
using namespace std;
vector<long long> sa[N],sb[N];
vector<int> ts[N];
int x1[N],x2[N],y1[N],y2[N],a[N],b[N];
inline long long psum(vector<long long>& v){
	return v.empty()?0:v.back();
}
void upd(int x,int ua,int ub,int ut){
	while(x<N){
		sa[x].push_back(psum(sa[x])+ua);
		sb[x].push_back(psum(sb[x])+ub);
		ts[x].push_back(ut);
		x+=x&-x;
	}
}
pair<long long,long long> qry(int x,int qt){
	long long ra=0,rb=0;
	while(x){
		int id=upper_bound(ts[x].begin(),ts[x].end(),qt)-ts[x].begin();
		if(id){
			ra+=sa[x][id-1];
			rb+=sb[x][id-1];
		}
		x-=x&-x;
	}
	return make_pair(ra,rb);
}
int main(){
	int n,m;
	vector<int> seg(1,-100);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d%d%d",&x1[i],&x2[i],&y1[i],&a[i],&b[i],&y2[i]);
		seg.push_back(x1[i]);
		seg.push_back(x2[i]);
	}
	sort(seg.begin(),seg.end());
	seg.resize(unique(seg.begin(),seg.end())-seg.begin());
	for(int i=1;i<=n;i++){
		x1[i]=lower_bound(seg.begin(),seg.end(),x1[i])-seg.begin()+1;
		x2[i]=lower_bound(seg.begin(),seg.end(),x2[i])-seg.begin()+1;
		upd(1,0,y1[i],i);
		upd(x1[i],a[i],b[i]-y1[i],i);
		upd(x2[i],-a[i],y2[i]-b[i],i);
	}
	scanf("%d",&m);
	int M=1e9;
	long long last=0;
	while(m--){
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		x=(x+last)%M;
		int id=lower_bound(seg.begin(),seg.end(),x)-seg.begin();
		auto pl=qry(id,l-1);
		auto pr=qry(id,r);
		last=(pr.first-pl.first)*x+pr.second-pl.second;
		printf("%lld\n",last);
	}
	return 0;
}