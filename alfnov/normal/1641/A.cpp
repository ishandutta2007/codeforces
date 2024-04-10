//testing solution
#include<bits/stdc++.h> 
using namespace std;
int a[1100000];
multiset<long long> ms;
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		ms.clear();
		int n,x;
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		map<long long,int>mm;
		for(int i=1;i<=n;i++) ms.insert(a[i]);
		for(int i=1;i<=n;i++) mm[a[i]]++;
		int r=0;
		for(int i=1;i<=n;i++){
			if((a[i]%x>0)||(mm[a[i]/x]==0)){
				if((i>1)&&(a[i]==a[i-1])) continue;
				long long y=a[i];
				int t=0;
				for(;;y*=x){
					//cout<<ms.count()<<endl;
					int uu=mm[y];
					if(uu==0) break;
					r+=min(t,uu);
					t=uu-min(t,uu);
					//cout<<t<<endl;
				} 
				//printf("%d\n",r);
			} 
		}
		printf("%d\n",n-2*r);
	} 
	return 0;
}