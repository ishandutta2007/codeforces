#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
int qmin(int a, int b){
	return (a < b) ? a : b;
}
int qmax(int a, int b){
	return (a > b) ? a : b;
}
int qabs(int a){
	return (a < 0) ? -a : a;
}

int T;
int n;
int a[100100];
int max_dist;
int min_val, max_val;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		max_dist = 0;
		min_val = 0x3f3f3f3f;
		max_val = 0;
		rep(i, n) scanf("%d", &a[i]);
		rep(i, n-1){
			if(a[i] == -1 && a[i+1] == -1) continue;
			if(a[i] == -1){
				min_val = qmin(min_val, a[i+1]);
				max_val = qmax(max_val, a[i+1]);
			} else if(a[i+1] == -1){
				min_val = qmin(min_val, a[i]);
				max_val = qmax(max_val, a[i]);
			} else {
				max_dist = qmax(max_dist, qabs(a[i] - a[i+1]));
			}
		}
		int dist = max_val - min_val;
		dist = dist/2 + dist%2;
		dist = qmax(dist, max_dist);
		cout << dist << " " << ((min_val == 0x3f3f3f3f) ? 0 : (min_val + dist)) << endl;
	}
	return 0;
}