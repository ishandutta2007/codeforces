#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
PII in[N];
PII in2[N];
set <PII> fA, fB;
vector <pair <PII, int> > ans;

void nie(){
	puts("NO");
	exit(0);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &in[i].st);
		in[i].nd = i;
	}
	
	for(int i = 1; i <= n; ++i){
		scanf("%d", &in2[i].st);
		in2[i].nd = i;
	}
	
	sort(in + 1, in + n + 1);
	sort(in2 + 1, in2 + n + 1);
	
	LL s = 0;
	for(int i = 1; i <= n; ++i){
		s += in[i].st - in2[i].st;
		if(in[i].st > in2[i].st)
			fB.insert({in[i].st, i});
		else if(in[i].st < in2[i].st)
			fA.insert({in[i].st, i});
	}
	
	if(s != 0)
		nie();	
	
	while(fA.size()){
		int x1 = (*fA.begin()).st;
		int x2 = (*fB.begin()).st;
		
		int id1 = (*fA.begin()).nd;
		int id2 = (*fB.begin()).nd;
		
		if(in2[id1].st > in2[id2].st)
			nie();
		
		int dx1 = in2[id1].st - x1;
		int dx2 = x2 - in2[id2].st;
		
		fA.erase(fA.begin());
		fB.erase(fB.begin());
		ans.push_back({{in[id1].nd, in[id2].nd}, min(dx1, dx2)});

		if(dx1 < dx2)
			fB.insert({x2 - dx1, id2});
		else if(dx1 > dx2)
			fA.insert({x1 + dx2, id1});
	}
	
	puts("YES");
	printf("%d\n", (int)ans.size());
	for(auto v: ans)
		printf("%d %d %d\n", v.st.st, v.st.nd, v.nd);

	return 0;
}