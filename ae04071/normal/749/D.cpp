#include <stdio.h>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#define mp std::make_pair

typedef std::pair<int, int> ip;

int n,q;
ip arr[200000];
int order[200001];
int first[200001];

std::vector<int> ind[200001];

int main()
{

	scanf("%d", &n);
	for(int i=0;i<n;i++) {
		scanf("%d %d",&arr[i].first, &arr[i].second);
	}

	std::vector<ip> oo;
	for(int i=1; i<=n;i++) {
		first[i]=-1;
		order[i]=n;
	}

	int size=0;
	for(int i=n-1;i>=0;i--) {
		if(first[arr[i].first] ==-1) {
			oo.push_back(mp(arr[i].first,size));
			size++;
			order[arr[i].first]=size-1;
			first[arr[i].first]=arr[i].second;
		}
	}

	for(int i=0;i<n;i++) {
		ind[arr[i].first].push_back(i);
	}

	scanf("%d", &q);
	int k, min;
	int num;
	while(q--) {
		scanf("%d",&k);
		std::vector<ip> res;
		for(int i=0;i<k;i++) {
			scanf("%d",&num);
			res.push_back(mp(order[num], num));
		}
		std::sort(res.begin(),res.end());


		int i=0;
		for(int j=0;j<k;j++,i++) {
			if(i>=oo.size()) break;
			if(res[j].first > i) break;
			else if(res[j].first == i-1) i--;
		}
		if(i>=oo.size()) printf("0 0\n");
		else if(i == oo.size()-1) {
			printf("%d %d\n", oo[i].first, arr[ind[oo[i].first][0]].second);
		}
		else {
			int j=i,a=i+1;
			for(; j<k; j++,a++) {
				if(a>=oo.size()) break;
				if(res[j].first > a) break;
				else if(res[j].first == a-1) a--;
			}
			if(a>=oo.size()) printf("%d %d\n", oo[i].first, arr[ind[oo[i].first][0]].second);
			else {
				int t=ind[oo[a].first][ind[oo[a].first].size()-1];
				int idx=*std::upper_bound(ind[oo[i].first].begin(), ind[oo[i].first].end(), t);
		
				printf("%d %d\n", oo[i].first, arr[idx].second);
			}
			
		}
	}

	return 0;
}