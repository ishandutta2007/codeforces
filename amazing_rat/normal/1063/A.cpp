#include<bits/stdc++.h>
using namespace std;

char s[100010];

int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",s) ;
	sort(s,s+n) ;
	printf("%s\n",s);
	
	return 0;
}