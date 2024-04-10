#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 2007;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

struct Point{
	int x, y;
	int id;
};

int n;
char dir[N];
vector <Point> in;

bool cmp1(Point a, Point b){
	if(a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

Point Centre;
bool cmp2(Point a, Point b){
	if(1LL * (a.x - Centre.x) * (b.y - Centre.y) < 1LL * (b.x - Centre.x) * (a.y - Centre.y))
		return true;
	return false;
}

void solve(vector <Point> &cur, Point root, int nr){
	printf("%d ", root.id);
	if(cur.size() == 1){
		printf("%d\n", cur[0].id);
		return;
	}
	
	Centre = root;
	sort(cur.begin(), cur.end(), cmp2);
	
	if(dir[nr] == 'L'){
		Point nextRoot = cur.back();
		cur.pop_back();
		solve(cur, nextRoot, nr + 1);
	}
	else{
		reverse(cur.begin(), cur.end());
		Point nextRoot = cur.back();

		cur.pop_back();
		solve(cur, nextRoot, nr + 1);
	}
}

int main(){
	scanf("%d", &n);
	in.resize(n);
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &in[i].x, &in[i].y);
		in[i].id = i + 1;
	}
	
	scanf("%s", dir + 1);
	sort(in.begin(), in.end(), cmp1);
	reverse(in.begin(), in.end());
	
	Point s = in.back();
	in.pop_back();

	solve(in, s, 1);
	return 0;
}