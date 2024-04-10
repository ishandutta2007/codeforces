#include<bits/stdc++.h>
#define N 100100
const int MOD=1000000007;
using namespace std;
struct qry{
	int id;
	int l;
	int x;
	bool operator<(const qry& rhs)const{return l<rhs.l;}
}Q[N];
int a[N],ans[N];
int p2[N];
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	p2[0]=1;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		p2[i+1]=(p2[i]+p2[i])%MOD;
	}
	for(int i=0;i<q;i++){
		Q[i].id=i;
		scanf("%d%d",&Q[i].l,&Q[i].x);
		Q[i].l--;
	}
	sort(Q,Q+q);
	int cur=0,i2;
	vector<int> v,piv;
	for(int i=0;i<q;i++){
		while(cur<=Q[i].l){
			for(int j=0;j<v.size();j++){
				if(a[cur]&piv[j]) a[cur]^=v[j];
			}
			if(a[cur]){
				v.push_back(a[cur]);			
				piv.push_back(a[cur]&-a[cur]);
			}
			cur++;
		}
		for(int j=0;j<v.size();j++){
			if(Q[i].x&piv[j]) Q[i].x^=v[j];
		}
		if(!Q[i].x) ans[Q[i].id]=p2[cur-v.size()];
	}
	for(int i=0;i<q;i++) printf("%d\n",ans[i]);
}