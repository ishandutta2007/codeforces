#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 255;

int cnt;
int n, a, b, k, f;
map <string, int> M;
map <PII, int> Edge;

int main(){
	scanf("%d %d %d %d %d", &n, &a, &b, &k, &f);
	int last = 0;	
	int res = 0;
	for(int i = 1; i <= n; ++i){
		string aa, bb;
		cin >> aa >> bb;
		if(!M.count(aa))
			M[aa] = ++cnt;
		if(!M.count(bb))
			M[bb] = ++cnt;
		
		int x = M[aa], y = M[bb];
		Edge[{min(x, y), max(x, y)}] += last == x ? b : a;
		res += last == x ? b : a;
		last = y;		
	}
	
	priority_queue <int> Q;
	for(auto v: Edge)
		Q.push(v.nd);
	
	while(!Q.empty() && k > 0){
		int xd = Q.top();
		Q.pop();
		
		if(xd <= f)
			break;
		--k;
		res += f - xd;
	}
	
	printf("%d\n", res);
	return 0;
}