#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n,m,x,a[100005],b[100005];
set<pair<int,int> >s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&x);
		s.clear();
		for(int i=1;i<=m;++i)s.insert(mp(0,i));
		for(int i=1;i<=n;++i){
			scanf("%d",a+i);
			pair<int,int> p=*s.begin();
			s.erase(p);
			b[i]=p.second;
			p.first+=a[i];
			s.insert(p);
		}
		printf("YES\n");
		for(int i=1;i<n;++i)printf("%d ",b[i]);
		printf("%d\n",b[n]);
	}
    return 0;
}