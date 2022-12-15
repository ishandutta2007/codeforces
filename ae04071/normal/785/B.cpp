#include <stdio.h>
#include <utility>
#include <algorithm>

typedef std::pair<int, int> ip;
ip a[200000],b[200000];
int n,m;

bool cmp(const ip &a, const ip &b) {
	if(a.second!=b.second) return a.second<b.second;
	else return a.first<b.first;
}

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
	}
	scanf("%d",&m);
	for(int j=0;j<m;j++)
		scanf("%d %d", &b[j].first, &b[j].second);

	std::sort(a,a+n);
	std::sort(b,b+m,cmp);

	int max=0;
	max=std::max(max, a[n-1].first-b[0].second);
	std::sort(a,a+n,cmp);
	std::sort(b,b+m);
	max=std::max(max, b[m-1].first-a[0].second);

	printf("%d\n",max);

	return 0;
}