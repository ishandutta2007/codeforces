#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)

int main(){
	int n,a,ans[int(4e5)],k=0;
	ans[0] = 1;
	set<int> s;
	scanf("%d",&n);
	rep(i,0,n){
		scanf("%d",&a);
		if(s.count(a)){
			++k;
			s.clear();
			ans[2*k-1] = i+1;
			ans[2*k] = i+2;
		} else {
			s.insert(a);
		}
	}
	if(!s.empty()){
		if(k == 0){
			puts("-1");
			return 0;
		}
		ans[2*k-1] = n;
	}
	printf("%d\n",k);
	rep(i,0,k)
		printf("%d %d\n",ans[2*i],ans[2*i+1]);
}