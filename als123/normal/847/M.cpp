#include <cmath>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
//Quick Read
int Read(){
	int x=0;
	bool neg=false;
	char c=getchar();
	while(isdigit(c)==false)neg^=c=='-',c=getchar();
	while(isdigit(c)==true)x=x*10+c-'0',c=getchar();
	return neg==true?-x:x;
}
inline void Read(int &x){x=Read();}
//Main
int main(){
	// freopen("M.in","r",stdin);
	// freopen("M.out","w",stdout);
	bool gan=true;
	int n=Read(),temp=Read(),last=Read(),gap=last-temp;
	if(n==2){
		printf("%d\n",last+gap);
		return 0;
	}
	for(int i=3;i<=n;++i){
		int x=Read();
		if(x-last!=gap)gan=false;
		if(i==n){
			if(gan==true)printf("%d\n",x+gap);
			else printf("%d\n",x);
		}
		last=x;
	}
	return 0;
}