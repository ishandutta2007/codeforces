#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define N 100100
#define S 500
using namespace std;
int t[N],l[N],r[N];
int num[N*2],a[N];
const int bs=4000;
int cnt[N*2],cf[S];
int ans[N];
struct qry{
	int l,r,t;
	qry(int l,int r,int t):l(l),r(r),t(t){}
	bool operator<(qry rhs)const{
		if(l/bs!=rhs.l/bs || t/bs!=rhs.t/bs) return make_pair(l/bs,t/bs)<make_pair(rhs.l/bs,rhs.t/bs);
		else return r>rhs.r;
	}
};
void add(int x){
	if(cnt[a[x]]<S) cf[cnt[a[x]]]--;
	cnt[a[x]]++;
	if(cnt[a[x]]<S) cf[cnt[a[x]]]++;
}
void del(int x){
	if(cnt[a[x]]<S) cf[cnt[a[x]]]--;
	cnt[a[x]]--;
	if(cnt[a[x]]<S) cf[cnt[a[x]]]++;
}
int main(){
	int n,q,m=0;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		num[i-1]=a[i];
	}
	m=n;
	vector<qry> v;
	for(int i=0;i<q;i++){
		scanf("%d%d%d",&t[i],&l[i],&r[i]);
		if(t[i]==2) num[m++]=r[i];
		else v.push_back(qry(l[i],r[i],i));
	}
	sort(num,num+m);
	m=unique(num,num+m)-num;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(num,num+m,a[i])-num;
	}
	for(int i=0;i<q;i++){
		if(t[i]==2){
			r[i]=lower_bound(num,num+m,r[i])-num;
		}
	}
	sort(all(v));
	int cl=1,cr=0,ct=0;
	cf[0]=1e9;
	for(auto qry:v){
		while(cr<qry.r){
			add(++cr);
		}
		while(cl>qry.l){
			add(--cl);
		}
		while(cr>qry.r){
			del(cr--);
		}
		while(cl<qry.l){
			del(cl++);
		}
		while(ct!=qry.t){
			if(t[ct]==2){
				if(cl<=l[ct] && l[ct]<=cr) del(l[ct]);
				swap(a[l[ct]],r[ct]);
				if(cl<=l[ct] && l[ct]<=cr) add(l[ct]);
			}
			if(ct<qry.t) ct++;
			else ct--;
		}
		while(cf[ans[qry.t]]) ans[qry.t]++;
	}
	for(int i=0;i<q;i++){
		if(t[i]==1) printf("%d\n",ans[i]);
	}
	return 0;
}