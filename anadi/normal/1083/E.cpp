#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
vector <PLL> Hull;
pair <PII, LL> wsp[N];

LL eval(int id, LL v){
	return Hull[id].st * v + Hull[id].nd;
}

LL get(PLL p1, PLL p2){
	return (p2.nd - p1.nd) / (p1.st - p2.st);
}

void add(LL a, LL b){
	while(Hull.size() > 1){
		LL place = get(Hull.back(), {a, b});
		LL place2 = get(Hull[Hull.size() - 2], Hull.back());
		
		if(place < place2)
			break;
		Hull.pop_back();
	}
	
	Hull.push_back({a, b});
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d %d %lld", &wsp[i].st.st, &wsp[i].st.nd, &wsp[i].nd);
	sort(wsp + 1, wsp + n + 1);
	
	int wsk = 0;
	Hull.push_back({0, 0});
	
	LL res = 0LL;
	for(int i = 1; i <= n; ++i){
		while(wsk + 1 < Hull.size() && eval(wsk, wsp[i].st.nd) < eval(wsk + 1, wsp[i].st.nd))
			++wsk;
		
		LL v = eval(wsk, wsp[i].st.nd) - wsp[i].nd + 1LL * wsp[i].st.st * wsp[i].st.nd;
		res = max(res, v);
		
		add(-wsp[i].st.st, v);
		wsk = min(wsk, (int)Hull.size() - 1);
	}
	
	printf("%lld\n", res);
	return 0;
}