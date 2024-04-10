#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	set<int> s;
	for(int i=0;i<=n;i++) s.insert(i);
	printf("1");
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		s.erase(x);
		printf(" %d",i+1-(n-*s.rbegin()));
	}
	puts("");
	return 0;
}