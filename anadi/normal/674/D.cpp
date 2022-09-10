#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define PLI pair <LL, int>
#define PII pair <int, int>
#define PLL pair <LL, LL>
#define mp make_pair
#define st first
#define nd second

const int mxn = 1e5 + 9;

int n, q;
int sub[mxn];
LL val[mxn];
LL fans[mxn];
int d[mxn];
set <PLI> child[mxn];
set <PLI> MN;
set <PLI> MX;

void add(int a){
	if(child[a].size() == 0)
		return;

	set <PLI>::iterator it = child[a].end();
	--it;
	PLI x = *it;
	x.st += fans[a] / (LL)(d[a] + 1);
	MX.insert(x);

	it = child[a].begin();
	x = *it;
	x.st += fans[a] / (LL)(d[a] + 1);
	MN.insert(x);
}

void usun(int a){
	if(child[a].size() == 0)
		return;
	
	set <PLI>::iterator it = child[a].end();
	--it;
	PLI x = *it;
	x.st += fans[a] / (d[a] + 1);
	it = MX.find(x);
	if(it != MX.end())
		MX.erase(it);
	
	it = child[a].begin();
	x = *it;
	x.st += fans[a] / (d[a] + 1);
	it = MN.find(x);
	if(it != MN.end())
		MN.erase(it);
}

void wywal(int a, int from){
	set <PLI>::iterator it = child[from].find(mp(val[a], a));
	if(it != child[from].end())
		child[from].erase(it);
}

void dodaj(int a, int to){
	child[to].insert(mp(val[a], a));
}

void change(int a, int from, int to){
	usun(from);
	usun(sub[from]);
	usun(to);
	usun(sub[to]);
	usun(sub[sub[from]]);
	usun(sub[sub[to]]);
	
	wywal(a, from);
	wywal(from, sub[from]);
	wywal(to, sub[to]);
	wywal(sub[from], sub[sub[from]]);
	wywal(sub[to], sub[sub[to]]);
	
	val[from] += 1LL * d[from] * (fans[from] / (LL)(d[from] + 1));
	val[sub[from]] -= fans[from] / (LL)(d[from] + 1);
	d[from]--;
	val[from] -= 1LL * d[from] * (fans[from] / (LL)(d[from] + 1));
	val[sub[from]] += fans[from] / (LL)(d[from] + 1);
	
	val[to] += 1LL * d[to] * (fans[to] / (LL)(d[to] + 1));
	val[sub[to]] -= fans[to] / ((LL)d[to] + 1);
	d[to]++;
	val[to] -= 1LL * d[to] * (fans[to] / (LL)(d[to] + 1));	
	val[sub[to]] += fans[to] / ((LL)d[to] + 1);
	
	val[from] -= fans[a] / (LL)(d[a] + 1);
	val[to] += fans[a] / (LL)(d[a] + 1);
	
	sub[a] = to;
	dodaj(a, to);
	dodaj(from, sub[from]);
	dodaj(to, sub[to]);
	dodaj(sub[to], sub[sub[to]]);
	dodaj(sub[from], sub[sub[from]]);
	
	add(from);
	add(sub[from]);
	add(to);
	add(sub[to]);
	add(sub[sub[to]]);
	add(sub[sub[from]]);
}

int main(){
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i)
		scanf("%I64d", &fans[i]);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &sub[i]);
		d[sub[i]]++;
		d[i]++;
	}
	
	for(int i = 1; i <= n; ++i){
		val[i] += fans[i] - 1LL * d[i] * (fans[i] / (LL)(d[i] + 1));
		val[sub[i]] += fans[i] / (LL)(d[i] + 1);
	}
	
	for(int i = 1; i <= n; ++i)
		child[sub[i]].insert(mp(val[i], i));
	for(int i = 1; i <= n; ++i)
		add(i);
	
	while(q--){
		int type;
		scanf("%d", &type);

		if(type == 1){
			int a, to;
			scanf("%d %d", &a, &to);
			change(a, sub[a], to);
		}

		if(type == 2){
			int a;
			scanf("%d", &a);
			printf("%I64d\n", val[a] + fans[sub[a]] / (LL)(d[sub[a]] + 1));
		}

		if(type == 3){
			set <PLI>::iterator it = MN.begin();
			printf("%I64d ", (*it).st);
			it = MX.end();
			--it;
			printf("%I64d\n", (*it).st);
		}
	}
	
	return 0;
}