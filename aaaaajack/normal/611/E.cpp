#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
int main(){
	int a[3];
	multiset<int> e;
	int n,ans=0;
	scanf("%d%d%d%d",&n,&a[0],&a[1],&a[2]);
	sort(a,a+3);
	while(n--){
		int x;
		scanf("%d",&x);
		e.insert(x);
	}
	if(*(e.rbegin())>a[0]+a[1]+a[2]) puts("-1");
	else{
		while(!e.empty()&&*e.rbegin()>a[1]+a[2])  ans++,e.erase(--e.end());
		while(!e.empty()&&*e.rbegin()>a[0]+a[2]){
			ans++;
			e.erase(--e.end());
			auto it=e.upper_bound(a[0]);
			if(it!=e.begin()){
				e.erase(--it);
			}
		}
		while(!e.empty()&&*e.rbegin()>max(a[2],a[0]+a[1])){
			ans++;
			e.erase(--e.end());
			auto it=e.upper_bound(a[1]);
			if(it!=e.begin()){
				e.erase(--it);
			}
		}
		if(a[0]+a[1]>a[2]){
			while(!e.empty()&&*e.rbegin()>a[2]){
				ans++;
				e.erase(--e.end());
				auto it=e.upper_bound(a[2]);
				if(it!=e.begin()){
					e.erase(--it);
				}
			}
		}
		while(!e.empty()&&*e.begin()<=a[0]){
			ans++;
			e.erase(e.begin());
			auto it=e.upper_bound(a[2]);
			if(it!=e.begin()) e.erase(--it);
			it=e.upper_bound(a[1]);
			if(it!=e.begin()) e.erase(--it);
		}
		a[1]+=a[0];
		if(a[1]>a[2]) swap(a[1],a[2]);
		while(!e.empty()){
			ans++;
			e.erase(--e.end());
			auto it=e.upper_bound(a[1]);
			if(it!=e.begin()) e.erase(--it);
		}
		printf("%d\n",ans);
	}
	return 0;
}