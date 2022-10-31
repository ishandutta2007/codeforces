#include<cstdio>
#include<set>
#include<algorithm>
#define N 100100 
using namespace std;
struct pack{
	int low;
	int high;
	int id;
	bool operator<(pack rhs)const{return make_pair(low,high)<make_pair(rhs.low,rhs.high);}
}part[N],actor[N];
int k[N],ans[N],cnt[N];
struct cmp{
	bool operator()(const pack&	a,const pack& b)const{
		return a.high<b.high;
	}
};
int main(){
	int n,m,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d%d",&part[i].low,&part[i].high),part[i].id=i;
	scanf("%d",&m);
	for(i=0;i<m;i++) scanf("%d%d%d",&actor[i].low,&actor[i].high,&k[i]),actor[i].id=i;
	sort(part,part+n);
	sort(actor,actor+m);
	multiset<pack,cmp> s;
	multiset<pack,cmp>::iterator it;
	j=0;
	for(i=0;i<n;i++){
		while(j<m&&actor[j].low<=part[i].low){
			s.insert(actor[j++]);
		}
		it=s.lower_bound(part[i]);
		if(it==s.end()) break;
		ans[part[i].id]=it->id+1;
		cnt[it->id]++;
		if(cnt[it->id]==k[it->id]) s.erase(it);
	}
	if(i<n) printf("NO\n");
	else{
		printf("YES\n");
		for(i=0;i<n;i++){
			printf("%d%c",ans[i],i<n-1?' ':'\n');
		}
	}
	return 0;
}