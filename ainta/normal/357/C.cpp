#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
set<int>Set;
set<int>::iterator it,it2,it3;
int n,i,m,w[300100],a,b,c;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		Set.insert(i);
	}
	while(m--){
		scanf("%d%d%d",&a,&b,&c);
		it=Set.lower_bound(a);
		it2=Set.lower_bound(b+1);
		for(;it!=it2;){
			if(*it != c){
				it3=it;
				w[*it]=c;
				it++;
				Set.erase(it3);
			}
			else it++;
		}
	}
	for(i=1;i<=n;i++){
		printf("%d ",w[i]);
	}
	return 0;
}