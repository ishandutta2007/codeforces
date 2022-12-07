#include <cmath>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
//Constant
const int N=100000;
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
//Check
int n;
char str[N+1];
bool Check(int step){
	int l=0,r=0;
	for(int i=1;i<=n;++i){
		if(str[i]=='*'&&i>r&&l==0)l=i;
		else if(str[i]=='P'){
			if(l!=0){
				int need=i-l;
				if(need>step)return false;
				l=0,r=std::max(r,std::max(i+step-need*2,i+(step-need)/2));
			}
			else r=std::max(r,i+step);
		}
	}
	if(l!=0)return false;
	return true;
}
//Binary Search
int Binary_Search(){
	int l=1,r=n*2;
	while(l<=r){
		int mid=l+r>>1;
		if(Check(mid)==true)r=mid-1;
		else l=mid+1;
	}
	return r+1;
}
//Main
int main(){
	// freopen("E.in","r",stdin);
	// freopen("E.out","w",stdout);
	Read(n);
	scanf("%s",str+1);
	int ans=Binary_Search();
	printf("%d\n",ans);
	return 0;
}