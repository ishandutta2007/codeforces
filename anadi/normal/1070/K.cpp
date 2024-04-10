#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 1e6 + 7;

int n, k;
int in[N];

int main(){
	scanf("%d %d", &n, &k); 
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]), in[i] += in[i - 1];
	
	if(in[n]%k != 0){
		puts("No");
		return 0;
	}
	
	vector <int> res; int s = in[n] / k, last = 0;
	for(int i = 1; i <= n; ++i){
		if(in[i] - in[last] > s){
			puts("No");
			return 0;
		}
		
		if(in[i] - in[last] == s){
			res.push_back(i - last);
			last = i;
		}
	}
	
	if(res.size() != k){
		puts("No");
		return 0;
	}
	
	puts("Yes");
	for(int v: res)
		printf("%d ", v);
	return 0;
}