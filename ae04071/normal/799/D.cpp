#include <cstdio>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <utility>

typedef long long lli;
typedef std::pair<lli, lli> ip;
int a,b,h,w,n;
int arr[100000];
std::set<ip> t;

int main() {
	scanf("%d%d%d%d%d",&a,&b,&h,&w,&n);
	for(int i=0;i<n;i++) scanf("%d",arr+i);
	std::sort(arr,arr+n);
	std::queue<ip>que;
	que.push(ip(h*1ll,w*1ll));
	if(h>=a&&w>=b||w>=a&&h>=b) {
		printf("0\n");
		return 0;
	}

	int cnt=1;
	while(!que.empty()) {
		int sz=que.size();
		while(sz--) {
			ip now=que.front();que.pop();
			if(now.first<a) {
				lli na=now.first*arr[n-cnt];
				if(na>=100000) na=100000;
				if(na>=a&&now.second>=b||na>=b&&now.second>=a) {
					printf("%d\n",cnt);
					return 0;
				}
				if(t.find(ip(na,now.second))==t.end()) {
					t.insert(ip(na,now.second));
					que.push(ip(na,now.second));
				}
			}
			if(now.second<b) {
				lli nb=now.second*arr[n-cnt];
				if(nb>=100000) nb=100000;
				if(now.first>=a&&nb>=b||now.first>=b&&nb>=a) {
					printf("%d\n",cnt);
					return 0;
				}
				if(t.find(ip(now.first,nb))==t.end()) {
					t.insert(ip(now.first,nb));
					que.push(ip(now.first,nb));
				}
			}
		}
		cnt++;
	}
	printf("-1\n");
	return 0;
}