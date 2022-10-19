#include<bits/stdc++.h>
using namespace std;
struct node{
	int tp,num;
}a[10];
int t,mp[10][4],mn=2;
int gt(){
	char c=getchar();
	while(c==' '||c=='\n')c=getchar();
	if(c=='m')return 1;
	if(c=='p')return 2;
	if(c=='s')return 3;
}
int main(){
	for(int i=1;i<=3;i++)scanf("%d",&a[i].num),a[i].tp=gt(),mp[a[i].num][a[i].tp]++;
	for(int i=1;i<=3;i++){
		int tot=0;
		for(int j=1;j<=9;j++){
			if(mp[j][i]==3){
				puts("0");
				return 0;
			}
			if(mp[j][i]==2)mn=1;
			if(mp[j][i]&&mp[j-1][i])tot++;
			else tot=1;
			if(j>2){
				if(mp[j][i]&&mp[j-2][i])mn=1;
			}
			if(tot==2)mn=1;
			if(tot==3){
				puts("0");
				return 0;
			}
		}
	}
	if(mn==1)puts("1");
	else puts("2");
	return 0;
}