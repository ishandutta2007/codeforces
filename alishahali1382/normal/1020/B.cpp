#include <bits/stdc++.h>

using namespace std;

int n, cur;
int p[1000 + 10];
int ans[1000 + 10];

int main(){
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		cin>>p[i];
		p[i]--;
	}
	for (int i=0; i<n; i++){
		int check[n];
		memset(check, 0, sizeof(check));
		cur=i;
		while (!check[cur]){
			check[cur]=1;
			cur=p[cur];
		}
		ans[i]=cur;
	}
	for (int i=0; i<n; i++){
		printf("%d ", ans[i]+1);
	}
	
	return 0;
}