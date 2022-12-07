#include <cmath>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
//Constant
const int D=7;
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
int sum[D+1];
int main(){
	// freopen("G.in","r",stdin);
	// freopen("G.out","w",stdout);
	int n=Read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=7;++j){
			char c=getchar();
			while(c!='0'&&c!='1')c=getchar();
			if(c=='1')++sum[j];
		}
	}
	int ans=0;
	for(int i=1;i<=7;++i)ans=std::max(ans,sum[i]);
	printf("%d\n",ans);
	return 0;
}