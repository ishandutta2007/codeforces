#include <stdio.h>
#include <string>
#include <iostream>

int main()
{
	int n;
	scanf("%d",&n);

	bool flag=true;
	int y=0;
	for(int i=0;i<n;i++) {
		int ti;
		std::string str;
		std::cin >> ti >> str;

		if(y==0) {
			if(str!="South") flag=false;
		}
		else if(y==20000){
			if(str!="North") flag=false;
		}
		if(str=="South") y+=ti;
		else if(str=="North") y-=ti;
		if(y<0|| y>20000) flag=false;
	}
	if(y!=0) flag=false;
	if(flag) printf("YES\n");
	else printf("NO\n");

	return 0;
}