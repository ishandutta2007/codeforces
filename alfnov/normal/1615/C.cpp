#include<bits/stdc++.h>
//#define only_one_test
using namespace std;
char s[200005],t[200005];
int main(){
	int T=1;
#ifndef only_one_test
	cin>>T;
#endif
	while(T--){
		int n;
		cin>>n;
		scanf("%s%s",s+1,t+1);
		int a1=0,a2=0,a=0,b=0;
		for(int i=1;i<=n;++i){
			if(s[i]=='1')++a;
			if(t[i]=='1')++b;
			if(s[i]!=t[i])++a1;
			else ++a2;
		}
		if(a!=b&&b!=n-a+1)printf("-1\n");
		else{
			int f1=0,f2=0;
			for(int i=1;i<=n;++i){
				if(s[i]=='0'&&t[i]=='1')++f1;
				if(s[i]=='1'&&t[i]=='0')++f2;
			}
			int flag=0;
			for(int L=0;L<=2*n;++L){
				if((L&1)&&(n-a-L/2)==f1&&(a-(L+1)/2)==f2){
					flag=1;
					printf("%d\n",L);
					break;
				}else if(L/2==f1&&L/2==f2){
					flag=1;
					printf("%d\n",L);
					break;
				}
			}
			if(!flag)printf("-1\n");
		}
	}
	return 0;
}