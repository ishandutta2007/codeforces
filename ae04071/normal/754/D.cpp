#include <stdio.h>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>
#include <functional>
#define mp std::make_pair

struct Node
{
	int le, ri;
	int idx;
	bool operator<(const Node &rhs) {
		if(le!=rhs.le) return le<rhs.le;
		else return ri>rhs.ri;
	}
};

int n, k;
Node arr[300000];

int main()
{
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) {
		scanf("%d %d", &arr[i].le, &arr[i].ri);
		arr[i].idx=i+1;
	}

	std::sort(arr, arr+n);

	std::priority_queue<int, std::vector<int>, std::greater<int>> que;
	int st=0;
	int max=0;
	for(int i=0;i<n;i++) {
		while(!que.empty()) {
			if(que.top()>=arr[i].le) break;
			que.pop();
		}
		que.push(arr[i].ri);
		if(que.size()>=k) {
			int tmp=que.top()-arr[i].le+1;
			if(max<tmp) {
				max=tmp;
				st=arr[i].le;
			}
			que.pop();
		}
	}
	printf("%d\n",max);
	if(max==0) {
		for(int i=0;i<k;i++)
			printf("%d ",i+1);
		return 0;
	}
	std::vector<int> res;
	for(int i=0;i<n;i++){
		if(k==0) break;
		if(arr[i].le<=st&& arr[i].ri>=st+max-1)
		{
			res.push_back(arr[i].idx);
			k--;
		}
	}

	std::sort(res.begin(),res.end());
	for(auto &it:res) {
		printf("%d ",it);
	}
	
	return 0;
}