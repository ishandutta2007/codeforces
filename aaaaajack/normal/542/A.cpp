#include<cstdio>
#include<cstdlib>
#include<utility>
#include<algorithm>
#define M 200100
#define x first
#define y second
using namespace std;
struct treap{
	treap *l,*r;
	int pri,mx,mn;
	pair<int,int> key;
	treap(){}
	treap(pair<int,int> _key):key(_key),pri(rand()),mx(_key.x-_key.y),mn(_key.y),l(NULL),r(NULL){}
};
inline int qmx(treap *t){
	return t?t->mx:0;
}

inline int qmn(treap *t){
	return t?t->mn:1023456789;
}
inline void pull(treap *t){
	t->mx=max(max(qmx(t->l),qmx(t->r)),t->key.x-t->key.y);
	t->mn=min(min(qmn(t->l),qmn(t->r)),t->key.y);
}
treap *merge(treap *a,treap *b){
	if(!a||!b) return a?a:b;
	if(a->pri>b->pri){
		a->r=merge(a->r,b);
		pull(a);
		return a;
	}
	else{
		b->l=merge(a,b->l);
		pull(b);
		return b;
	}
}
void split(treap *t,pair<int,int> k,treap *&a,treap *&b){
	if(!t){
		a=b=NULL;
		return;
	}
	if(t->key<k){
		a=t;
		split(a->r,k,a->r,b);
		pull(a);
	}
	else{
		b=t;
		split(b->l,k,a,b->l);
		pull(b);
	}
}
treap *erase(treap *t,pair<int,int> k){
	if(t->key==k){
		return merge(t->l,t->r);
	}
	else if(k<t->key){
		t->l=erase(t->l,k);
		pull(t);
		return t;
	}
	else{
		t->r=erase(t->r,k);
		pull(t);
		return t;
	}
}
void print(treap *t){
	if(!t) return;
	printf("(%d,%d)\n",t->key.y,t->key.x);
	print(t->l);
	print(t->r);
}
pair<pair<int,int>,int> cha[M];
pair<int,int> video[M];
int idc[M],idv[M];
bool cmpc(int i,int j){return cha[i]<cha[j];}
bool cmpv(int i,int j){return video[i]<video[j];}
int main(){
	int n,m,l,r,i,j,mr=-1,bst;
	long long ans=0,pans;
	pair<int,int> k;
	treap *t=NULL,*a,*b;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d%d",&video[i].x,&video[i].y);
		k=make_pair(video[i].y,video[i].x);
		split(t,k,a,b);
		t=merge(a,merge(new treap(k),b));
		idv[i]=i;
	}
	for(i=0;i<m;i++){
		scanf("%d%d%d",&cha[i].x.x,&cha[i].x.y,&cha[i].y);
		idc[i]=i;
	}
	sort(idv,idv+n,cmpv);
	sort(video,video+n);
	sort(idc,idc+m,cmpc);
	sort(cha,cha+m);
	for(i=0,j=0;i<m;i++){
		pans=ans;
		while(j<n&&video[j].x<=cha[i].x.x){
			mr=max(mr,video[j].y);
			t=erase(t,make_pair(video[j].y,video[j].x));
			j++;
		}
		split(t,make_pair(cha[i].x.y,cha[i].x.x),a,b);
		if(a) ans=max(ans,1LL*cha[i].y*qmx(a));
		if(b) ans=max(ans,1LL*cha[i].y*(cha[i].x.y-max(qmn(b),cha[i].x.x)));
		if(mr>=0) ans=max(ans,1LL*cha[i].y*(min(mr,cha[i].x.y)-cha[i].x.x));
		t=merge(a,b);
		if(ans>pans) bst=i;
	}
	if(ans){
		printf("%I64d\n",ans);
		for(i=0;i<n;i++){
			if(1LL*cha[bst].y*(min(video[i].y,cha[bst].x.y)-max(video[i].x,cha[bst].x.x))==ans){
				printf("%d %d\n",idv[i]+1,idc[bst]+1);
				break;
			}
		}
	}
	else{
		printf("0\n");
	}
	return 0;
}