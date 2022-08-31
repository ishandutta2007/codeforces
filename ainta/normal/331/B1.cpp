#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
set<int>Set;
int n,w[300001],i,Q,r[300001],L[101],IT[1300001],SZ=524288;
int sum(int a,int b){
	a+=SZ,b+=SZ;
	int s=0;
	while(a<=b){
		if(a&1)s+=IT[a];
		if(!(b&1))s+=IT[b];
		a=(a+1)>>1,b=(b-1)>>1;
	}
	return s;
}
void ins(int a,int b){
	a+=SZ;
	while(a){
		IT[a]+=b;
		a>>=1;
	}
}
void Do(int a){
	set<int>::iterator it=Set.lower_bound(a);
	int s,l=*it;
	if(it==Set.begin())s=1;
	else{
		it--;
		s=*it;s++;
		it++;
	}
	if(s<a){
		if(r[a-1]>r[a]){
			Set.insert(a-1);
			ins(a,1);
		}
	}
	if(a<l){
		if(r[a]>r[a+1]){
			Set.insert(a);
			ins(a+1,1);
		}
	}
	if(s>1 && r[s-1]<r[s]){
		it=Set.find(s-1);
		Set.erase(it);
		ins(s,-1);
	}
	if(l<n && r[l]<r[l+1]){
		it=Set.find(l);
		Set.erase(l);
		ins(l+1,-1);
	}
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&w[i]);
		r[w[i]]=i;
	}
	for(i=1;i<=n;i++){
		if(r[i]>r[i+1]){
			Set.insert(i);
			if(i!=n)ins(i+1,1);
		}
	}
	scanf("%d",&Q);
	int a,b,c;
	while(Q--){
		scanf("%d%d%d",&a,&b,&c);
		if(a==1){
			printf("%d\n",sum(b+1,c)+1);
		}
		else{
			swap(w[b],w[c]);
			swap(r[w[b]],r[w[c]]);
			Do(w[b]);
			Do(w[c]);
		}
	}
}