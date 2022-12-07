#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<fstream>
#include<cmath>
#include<stack>
#include<cstdlib>
#include<vector>
#include<ctime>
using namespace std;
int n;
int st=1;
vector <int> ans;
int main(){
	scanf("%d",&n);
	if(n%4==1||n%4==2){
		printf("1\n");
	}else printf("0\n");
	if(n%4==2) ans.push_back(2);
	else if(n%4==3) ans.push_back(3);
	st=st+n%4;
	while(st<=n){
		ans.push_back(st);
		ans.push_back(st+3);
		st+=4;
	}
	printf("%d ",ans.size());
	for(int i=0;i<ans.size();i++){
		printf("%d",ans[i]);
		if(i==ans.size()-1) printf("\n");
		else printf(" ");
	}
	return 0;
}