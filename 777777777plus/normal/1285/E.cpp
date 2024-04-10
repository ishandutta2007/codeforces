#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T;
int n;

struct nd{
	int l,r;
	friend bool operator < (nd a,nd b){
		return a.l<b.l||(a.l==b.l&&a.r<b.r);
	}
}a[N];

struct inv{
	int i;
	int rmax;
	multiset<int> r;
	int get(){
		multiset<int>::iterator it=r.end();
		return *(--it);
	}
}l[N],r[N];

int get(int mx,int l1,int r1){
	int lastl=l1;
	while(l1!=r1){
		int mid=l1+r1+1>>1;
		if(mx>=a[r[mid].i].l)l1=mid;
		else r1=mid-1;
	}
	if(mx<a[r[l1].i].l)return 0;
	return l1-lastl+1;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d%d",&a[i].l,&a[i].r);
		sort(a+1,a+n+1);
		int L=1,R=n+1;
		l[L].i=1;
		l[L].r.clear();
		l[L].r.insert(a[1].r);
		for(int i=2;i<=n;++i){
			if(a[i].l<=l[L].get()){
				l[L].r.insert(a[i].r);
			}
			else{
				++L;
				l[L].i=i;
				l[L].r.clear();
				l[L].r.insert(a[i].r);
			}
		}
		int ans=0;
		for(int i=n;i>=1;--i){
			if(l[L].i==i)L--;
			else{
				l[L].r.erase(l[L].r.find(a[i].r));
			}
			int tot=L+(n+1)-R;
			if(i!=n&&i!=1)tot-=get(l[L].get(),R,n);
			int rmax=a[i].r;
			while(R<=n&&a[r[R].i].l<=rmax){
				rmax=max(rmax,r[R].rmax);
				++R;
			}
			--R;
			r[R].i=i;
			r[R].rmax=rmax;
			ans=max(ans,tot);
		}
		printf("%d\n",ans); 
	}
}