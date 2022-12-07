#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<fstream>
#include<cmath>
#include<stack>
#include<cstdlib>
#include<sstream>
#include<ctime>
using namespace std;
int a,b,n;
int main(){
	scanf("%d%d%d",&n,&a,&b);
	for(int i=0;i*a<=n;i++){
		int c=n-i*a;
		if(c%b==0){
			printf("YES\n");
			printf("%d %d\n",i,c/b);
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}