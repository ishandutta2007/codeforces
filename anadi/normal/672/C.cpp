#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double LD;

#define PII pair <int, int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

const LL MX = 1e9 + 7LL;
const LL INF = 1e9 + 9LL;
const int mxn = 2e5 + 7;

int ax, ay, bx, by, tx, ty;
int n;
LD result = 0.0;
PII t[mxn];

LD odl(LD a, LD b, LD c, LD d){
	return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

int main(){
	scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &tx, &ty);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d %d", &t[i].st, &t[i].nd);
	
	for(int i = 1; i <= n; ++i)
		result += 2.0 * odl(t[i].st, t[i].nd, tx, ty);
	
	LD suma = result;
	result += min(odl(ax, ay, tx, ty), odl(bx, by, tx, ty));
	
	LD mx1 = -1e50, mx2 = -1e50;
	int with = 0;
	
	for(int i = 1; i <= n; ++i){
		LD d = 1.0 * odl(t[i].st, t[i].nd, tx, ty) - odl(bx, by, t[i].st, t[i].nd);
		if(d > mx1){
			mx2 = mx1;
			mx1 = d;
			with = i;
			continue;
		}

		if(d > mx2)
			mx2 = d;
	}
	
	result = min(result, suma - mx1);
	
	for(int i = 1; i <= n; ++i){
		LD d = 1.0 * odl(t[i].st, t[i].nd, tx, ty) - odl(ax, ay, t[i].st, t[i].nd);
		if(i == with)
			result = min(result, suma - d - mx2);
		else
			result = min(result, suma - d - mx1);
		result = min(result, suma - d);
	}
	
	printf("%.6lf\n", result);
	return 0;
}