#include<bits/stdc++.h>
using namespace std;
const int BBB=2200;
int n,m,q,a[100100],buc[200100],cnt[100100],res[100100];
vector<int>v;
struct modify{int x,bef,aft;}r[100100];
struct query{
	int l,r,t,id;
	friend bool operator<(const query&u,const query&v){
		if(u.l/BBB!=v.l/BBB)return u.l<v.l;
		if(u.r/BBB!=v.r/BBB)return u.r<v.r;
		return u.t<v.t;
	}
}p[100100];
#define DS(x) lower_bound(v.begin(),v.end(),x)-v.begin()
int L,R,T;
void Push(int x){cnt[buc[a[x]]]--,cnt[++buc[a[x]]]++;}
void Pop(int x){cnt[buc[a[x]]--]--,cnt[buc[a[x]]]++;}
void Tplus(){T++;if(L<=r[T].x&&r[T].x<=R)Pop(r[T].x),a[r[T].x]=r[T].aft,Push(r[T].x);else a[r[T].x]=r[T].aft;} 
void Tminus(){if(L<=r[T].x&&r[T].x<=R)Pop(r[T].x),a[r[T].x]=r[T].bef,Push(r[T].x);else a[r[T].x]=r[T].bef;T--;}
int ask(){for(int i=1;;i++)if(!cnt[i])return i;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),v.push_back(a[i]);
	for(int i=1,tp,x,y;i<=m;i++){
		scanf("%d%d%d",&tp,&x,&y);
		if(tp==1)++q,i--,m--,p[q].l=x,p[q].r=y,p[q].t=i,p[q].id=q;
		else r[i].x=x,r[i].bef=a[x],v.push_back(r[i].aft=a[x]=y);
	}
	sort(v.begin(),v.end()),v.resize(unique(v.begin(),v.end())-v.begin());
	for(int i=1;i<=n;i++)a[i]=DS(a[i]);
	for(int i=1;i<=m;i++)r[i].bef=DS(r[i].bef),r[i].aft=DS(r[i].aft);
	sort(p+1,p+q+1);
	L=1,R=0,T=m;
	for(int i=1;i<=q;i++){
		while(L>p[i].l)Push(--L);
		while(R<p[i].r)Push(++R);
		while(L<p[i].l)Pop(L++);
		while(R>p[i].r)Pop(R--);
		while(T<p[i].t)Tplus();
		while(T>p[i].t)Tminus();
		res[p[i].id]=ask();
	}
	for(int i=1;i<=q;i++)printf("%d\n",res[i]);
	return 0;
}