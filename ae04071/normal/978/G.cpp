#include <bits/stdc++.h>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
const lli inf=1e15;

int n,m;

struct data{
	int s,d,t,idx;
	data() {}
	bool operator<(const data &rhs)const {
		if(s!=rhs.s) return s<rhs.s;
		else return d<rhs.d;
	}
}arr[100];

struct qdata{
	int first,second,idx;
	qdata() {}
	qdata(int f,int s,int i):first(f),second(s),idx(i) {}
	bool operator<(const qdata &rhs)const {
		return first>rhs.first;
	}
};

int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) {
		scanf("%d%d%d",&arr[i].s,&arr[i].d,&arr[i].t);
		arr[i].idx=i+1;
	}
	sort(arr,arr+m);

	int j=0;
	priority_queue<qdata> que;
	priority_queue<int,vector<int>,greater<int>> el;
	
	vector<int> ans;
	for(int i=1;i<=n;i++) {
		for(;j<m && arr[j].s<=i;j++) que.push(qdata(arr[j].d,arr[j].t,arr[j].idx));
		if(!que.empty() && que.top().first<=i) {
			puts("-1");
			return 0;
		}
		if(!el.empty() && el.top()==i) {
			ans.push_back(m+1);
			el.pop();
			continue;
		}

		if(que.empty()) ans.push_back(0);
		else {
			qdata val=que.top();
			que.pop();
			ans.push_back(val.idx);
			val.second--;
			if(val.second==0) el.push(val.first);
			else que.push(val);
		}
	}
	for(int i=0;i<n;i++) printf("%d ",ans[i]);
	return 0;
}