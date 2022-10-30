#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
using namespace std;
int main(){
	int i,j,n,k,q,x,a[5010],ans;
	map<int,int> m;
	map<int,int>::iterator it;
	m[0]=0;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		for(j=1;j<=k;j++){
			m[a[i]*j]=j;
		}
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d",&x);
		ans=50;
		for(it=m.begin();it!=m.end();++it){
			if(m.count(x-it->first)){
				ans=min(ans,m[x-it->first]+it->second);
			}
		}
		if(ans>k) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}