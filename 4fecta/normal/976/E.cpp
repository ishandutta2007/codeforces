#include <bits/stdc++.h>

using namespace std;

const int N = 200 * 1000 + 9;

int n, a, b;
int hp[N], dmg[N];

bool cmp(int i, int j){
	if(hp[i] - dmg[i] != hp[j] - dmg[j])
		return hp[i] - dmg[i] > hp[j] - dmg[j];
	return i < j;
}

int get(int id){
	return  hp[id] > dmg[id]? hp[id] : dmg[id];
}

int main(){
	scanf("%d %d %d", &n, &a, &b);
	for(int i = 0; i < n; ++i)
		scanf("%d %d", hp + i, dmg + i);
	
	b = min(b, n);
	vector <int> p(n);
	for(int i = 0; i < n; ++i) p[i] = i;
	sort(p.begin(), p.end(), cmp);
	long long res = 0, sum = 0;
	for(int i = 0; i < n; ++i){
		int id = p[i];
		if(i < b) sum += get(id);
		else sum += dmg[id];
	}
	res = sum; 

	if(b == 0){
		printf("%lld\n", res);
		return 0;
	}
	
	long long x = (1LL << a);
	for(int i = 0; i < n; ++i){
		int id = p[i];
		long long nres = sum;
		if(i < b){ 
			nres -= get(id);
			nres += hp[id] * x;
			res = max(res, nres);
		}
		else{
			nres -= dmg[id];
			nres += hp[id] * x;			
			int id2 = p[b - 1];
			nres -= get(id2);
			nres += dmg[id2];
			res = max(res, nres);
			
		}		
	}
	
	printf("%lld\n", res);
	return 0;
}