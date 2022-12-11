//Solution by Tima
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
#define y1 sda
using namespace std;    
const int N = int(3e5), mod = int(1e9)  + 7; 

char s[N], t[N];

int n,m,q;

int a[N],b[N], e[N], o[N]; 

int main () {
	scanf("%s\n", s + 1);
	n = strlen(s + 1);
	scanf("%s", t + 1);
	m = strlen(t + 1);
	for(int i = 1; i <= n; i++){
		e[i] = e[i - 1] + (s[i] != 'A');
		if(s[i] == 'A') a[i] = a[i - 1] + 1;
	}
	for(int i = 1; i <= m; i++){
		o[i] = o[i - 1] + (t[i] != 'A'); 
		if(t[i] == 'A') b[i] = b[i - 1] + 1;
	}
	scanf("%d", &q);
	for(int i = 1,x,y,l,r; i <= q; i++){
		scanf("%d%d%d%d", &x, &y, &l, &r);
		int x1 = e[y] - e[x - 1], x2 = o[r] - o[l - 1];
		if(x1 > x2){
			printf("0");
			continue;
		}
		if((x1 & 1) != (x2 & 1)){
			printf("0");
			continue;
		}
		int a1 = min(a[y], y - x + 1);
		int a2 = min(b[r], r - l + 1);
		if(a2 > a1){
			printf("0");
			continue;
		}
		if(a1 == a2 && x2 > 0 && a1 == y - x + 1){
			printf("0");
			continue;
		}
		if(x1 == x2){
			if(a1 % 3 != a2 % 3){
				printf("0");
				continue;
			}
		}
		printf("1");
	}
	

return 0;
}