#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 111111;
int gcd(int x,int y){
	if(!y)
		return x;
	return gcd(y,x%y);
}
int n,w,a[N],l[N],r[N];
set<int> S;
set<int>::iterator it;
vector<int> ans;
void del(int x){
	int y=l[x],z=r[x];
	r[y]=z,l[z]=y;
	ans.push_back(x);
	S.erase(x);
	if(S.find(z)!=S.end())
		S.erase(z);
	if(gcd(a[y],a[z])==1)
		S.insert(z);
}
int main(){
	int T,i,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		for(i=1;i<=n;i++)
			r[i]=i%n+1,l[i%n+1]=i;
		S.clear();
		for(i=1;i<=n;i++)
			if(gcd(a[i],a[l[i]])==1)
				S.insert(i);
		ans.clear();
		x=2;
		w=n;
		while(w&&!S.empty()){
			it=S.lower_bound(x);
			if(it==S.end()){
				x=1;
				continue;
			}
			x=*it;
			del(x);
			x=r[r[x]];
			w--;
		}
		printf("%d ",ans.size());
		for(i=0;i<ans.size();i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}