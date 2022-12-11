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
using namespace std;    
const int N = int(1e5) + 10, mod = int(1e9)  + 7; 

int n,m;

int a[N],b[N];

pair <int,int> p[N];

int c[N], t[N][22], cv[N], res[N];

int c1[N],c2[N];

bool check(){
}

int main () {
	srand(time(0));
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= m;  i++){
		scanf("%d%d",&a[i],&b[i]);
		if(rand() & 1) swap(a[i],b[i]);
		p[i] = mp(a[i],b[i]);
	}
	random_shuffle(p + 1, p + m + 1); 
	for(int i = 1; i <= m; i++){
		a[i] = p[i].f;
		b[i] = p[i].s;
	}      
	int mx = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d",&c[i]);
		for(int j = 1; j <= c[i]; j++){
			scanf("%d",&t[i][j]);
			mx = max(mx,t[i][j]);
		}
	}
	int cur = 0;
	while(true){
		cur = 0;
		for(int i = 1; i <= mx; i++){
			cv[i] = rand() % 2 + 1;
		} 
		for(int i = 1; i <= n; i++) {
			res[i] = 0;
			c1[i] = 0;
			c2[i] = 0;
			for(int j = 1; j <= c[i]; j++){
				if(cv[t[i][j]] == 1) c1[i] = t[i][j];
				else c2[i] = t[i][j];
			}
		}
		for(int i = 1; i <= m; i++){
			if(!res[a[i]] && !res[b[i]]){
				if(c1[a[i]] && c2[b[i]]){
					cur++;
					res[a[i]] = c1[a[i]];
					res[b[i]] = c2[b[i]];	
				}
				else if(c2[a[i]] && c1[b[i]]){
					cur++;
					res[a[i]] = c2[a[i]];
					res[b[i]] = c1[b[i]];	
				}
				else if(c1[a[i]]){
					res[a[i]] = c1[a[i]];
					res[b[i]] = c1[b[i]];
				}
			}
			else if(res[a[i]] && res[b[i]]){
				if(cv[res[a[i]]] != cv[res[b[i]]]) cur++;
			}
			else if(res[a[i]]){
				if(cv[res[a[i]]] == 1){
					if(c2[b[i]]){
						cur++;
						res[b[i]] = c2[b[i]];
					}
					else{
						res[b[i]] = c1[b[i]];
					}
				}
				if(cv[res[a[i]]] == 2){
					if(c1[b[i]]){
						cur++;
						res[b[i]] = c1[b[i]];
					}
					else{
						res[b[i]] = c2[b[i]];
					}
				}
			}
			else{
				if(cv[res[b[i]]] == 1){
					if(c2[a[i]]){
						cur++;
						res[a[i]] = c2[a[i]];
					}
					else{
						res[a[i]] = c1[a[i]];
					}
				}
				if(cv[res[b[i]]] == 2){
					if(c1[a[i]]){
						cur++;
						res[a[i]] = c1[a[i]];
					}
					else{
						res[a[i]] = c2[a[i]];
					}
				}
			}
		}
		if(cur * 2 >= m){
			for(int i = 1; i <= n; i++) if(!res[i]) res[i] = t[i][1];
			for(int i = 1; i <= n; i++) printf("%d ",res[i]);
			printf("\n");
			for(int i = 1; i <= mx; i++) printf("%d ",cv[i]);
			return 0;
		}
	}

return 0;
}