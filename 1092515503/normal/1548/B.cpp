#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,cnt,tp,rt,bin[200100],res;
ll a[200100];
#define lson t[x].ch[0]
#define rson t[x].ch[1]
struct Treap{int ch[2],rd,sz;ll gcd,val;}t[200100];
int newnode(ll val){int x=(tp?bin[tp--]:++cnt);lson=rson=0,t[x].gcd=t[x].val=val,t[x].rd=rand()*rand(),t[x].sz=1;return x;}
void pushup(int x){
	t[x].gcd=t[x].val,t[x].sz=1;
	if(lson)t[x].gcd=__gcd(t[x].gcd,t[lson].gcd),t[x].sz+=t[lson].sz;
	if(rson)t[x].gcd=__gcd(t[x].gcd,t[rson].gcd),t[x].sz+=t[rson].sz;
}
void splitbyval(int x,ll k,int &u,int &v){
	if(!x){u=v=0;return;}
	if(t[x].val>=k)v=x,splitbyval(lson,k,u,lson);
	else u=x,splitbyval(rson,k,rson,v);
	pushup(x);
}
void splitbysz(int x,int k,int &u,int &v){
	if(!x){u=v=0;return;}
	if(t[lson].sz>=k)v=x,splitbysz(lson,k,u,lson);
	else u=x,splitbysz(rson,k-t[lson].sz-1,rson,v);
	pushup(x);
}
int merge(int x,int y){
	if(!x||!y)return x+y;
	if(t[x].rd<t[y].rd){t[x].ch[1]=merge(t[x].ch[1],y),pushup(x);return x;}
	else{t[y].ch[0]=merge(x,t[y].ch[0]),pushup(y);return y;}
}
void Insert(ll val){
//	printf("I:%lld\n",val);
	int u,v;
	splitbyval(rt,val,u,v);
	rt=merge(merge(u,newnode(val)),v);
}
void Delete(ll val){
//	printf("D:%lld\n",val);
	int u,v,w;
	splitbyval(rt,val,u,v);
	splitbysz(v,1,v,w);
	bin[++tp]=v;
	rt=merge(u,w);
}
void Iterate(int x){if(x)Iterate(lson),printf("[%d:%lld,%lld]",x,t[x].val,t[x].gcd),Iterate(rson);}
set<ll>s;
int main(){
	srand(17680321);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),cnt=tp=res=rt=0,s.clear();
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(int l=1,r=1;r<=n;r++){
			if(s.empty()){s.insert(a[r]),res=1;continue;}
			auto it=s.lower_bound(a[r]);
			if(it==s.end())Insert(a[r]-*--it);
			else if(it==s.begin())Insert(*it-a[r]);
			else{
				ll nxt=*it,prv=*--it;
				Delete(nxt-prv);
				Insert(a[r]-prv);
				Insert(nxt-a[r]);
			}
			s.insert(a[r]);
//			Iterate(rt),puts("");
			while(t[rt].gcd==1){
//				printf("[%d,%d]\n",l,r);
				auto it=s.find(a[l]);
				it=s.erase(it);
				if(it==s.end())Delete(a[l]-*--it);
				else if(it==s.begin())Delete(*it-a[l]);
				else{
					ll nxt=*it,prv=*--it;
					Delete(a[l]-prv);
					Delete(nxt-a[l]);
					Insert(nxt-prv);
				}
//				Iterate(rt),puts("");
				l++;
			}
			res=max(res,r-l+1);
		}
		printf("%d\n",res);
	}
	return 0;
}