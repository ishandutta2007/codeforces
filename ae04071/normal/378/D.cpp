#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>

using namespace std;
typedef pair<int,int> ip;
struct data {
	int val,c,idx;	
	bool operator<(const data &rhs) const {
		return val<rhs.val;
	}
};
int n,m,s,res[1000000];
data bug[100000],stu[100000];

bool Check(int md) {
	int idx=m-1,r=n-1;
	priority_queue<int,vector<int>,greater<int>>que;
	while(r>=0) {
		if(stu[r].val>=bug[idx].val) {
			que.push(stu[r].c); r--;
		}
		else break;
	}
	int sum=0;
	while(!que.empty()&&idx>=0) {
		int now=que.top(); que.pop();
		sum+=now;
		if(sum>s) return false;
		idx-=md;
		while(r>=0) {
			if(stu[r].val>=bug[idx].val) {
				que.push(stu[r].c); r--;
			}
			else break;
		}
	}
	return idx<0;
}
void Trace(int md) {
	int idx=m-1,r=n-1;
	priority_queue<ip,vector<ip>,greater<ip>>que;
	while(r>=0) {
		if(stu[r].val>=bug[idx].val) {
			que.push(ip(stu[r].c,stu[r].idx)); r--;
		}
		else break;
	}
	while(!que.empty()&&idx>=0) {
		ip now=que.top(); que.pop();
		for(int i=idx;i>=0&&i>idx-md;i--) {
			res[bug[i].idx]=now.second+1;
		}
		idx-=md;
		while(r>=0) {
			if(stu[r].val>=bug[idx].val) {
				que.push(ip(stu[r].c,stu[r].idx)); r--;
			}
			else break;
		}
	}
}
int main() {
	scanf("%d%d%d",&n,&m,&s);
	for(int i=0;i<m;i++) {
		scanf("%d",&bug[i].val);
		bug[i].idx=i;bug[i].c=0;
	}
	for(int i=0;i<n;i++) {
		scanf("%d",&stu[i].val);
		stu[i].idx=i;
	}
	for(int i=0;i<n;i++) {
		scanf("%d",&stu[i].c);
	}
	std::sort(bug,bug+m);
	std::sort(stu,stu+n);
	
	int lo=0,up=m+1;
	while(up-lo>1) {
		int md=(lo+up)>>1;
		if(Check(md)) up=md;
		else lo=md;
	}
	if(up==m+1) puts("NO");
	else {
		puts("YES");
		Trace(up);
		for(int i=0;i<m;i++) printf("%d ",res[i]);
	}
	
	return 0;
}