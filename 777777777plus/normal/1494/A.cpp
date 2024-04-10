#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;
 
int T;
 
int main(){
	scanf("%d",&T);
	while(T--){
		static char s[N];
		scanf("%s",s+1);
		int n=strlen(s+1);
		bool flag1=0;
		for(int i=0;i<2;++i)
		for(int j=0;j<2;++j)
		for(int k=0;k<2;++k){
			int a[3]={i,j,k};
			int top=0;
			bool flag=1;
			for(int t=1;t<=n;++t){
				if(a[s[t]-'A'])top++;
				else top--;
				if(top<0)flag=0;
			}
			if(top)flag=0;
			if(flag)flag1=1;
		}
		puts(flag1?"YES":"NO");
	}
}