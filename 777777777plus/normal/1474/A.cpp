#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n;
char s[N],t[N];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		scanf("%s",s+1);
		s[1]-='0';t[1]=1;
		int last=s[1]+t[1];
		for(int i=2;i<=n;++i){
			s[i]-='0';
			if(s[i]+1!=last)t[i]=1,last=s[i]+1;
			else t[i]=0,last=s[i];
		}
		for(int i=1;i<=n;++i)printf("%d",t[i]);
		printf("\n");
	}
}