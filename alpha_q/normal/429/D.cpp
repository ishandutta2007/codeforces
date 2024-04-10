#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAX = 100005;
const LL INF = 1e18;

struct node {
	LL x, y;
}; 

node points[MAX];

LL dist(int x, int y) {
	return (points[x].x - points[y].x) * (points[x].x - points[y].x) + (points[x].y - points[y].y) * (points[x].y - points[y].y);
}

bool compare(int i,int j) {
	return points[i].y < points[j].y;
}
	

LL solve(int left, int right) {
	if(left == right) return INF;
	if(left + 1 == right) return dist(left, right);
	vector<LL> idx;
	int mid = left + right >> 1;
	LL len = min(solve(left, mid), solve(mid + 1, right));
	for(int i = left; i <= right; i++)
		if((points[mid].x - points[i].x) * (points[mid].x - points[i].x) <= len)
			idx.push_back(i);
	sort(idx.begin(), idx.end(), compare);
	for(int i = 0; i < idx.size(); i++)
		for(int j = i + 1; j < idx.size(); j++) {
			int a = idx[i], b = idx[j];
			if((points[b].y - points[a].y) * (points[b].y - points[a].y) >= len) break;
			len = min(len, dist(a,b));
		}
	return len;
}

int main() {
	//freopen("input.txt", "r", stdin);

	int n; LL sum = 0, num; scanf("%d", &n);
	for (LL i = 1; i <= n; i++) {
		scanf("%I64d", &num); sum += num;
		points[i].x = i, points[i].y = sum; 
	}
	printf("%I64d", solve(1, n));
    return 0;
}