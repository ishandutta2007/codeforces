#include<bits/stdc++.h>
#define N 300100
using namespace std;
char s[N];
int main(){
	scanf("%s",s);
	s[strlen(s)+1]=0;
	s[strlen(s)]='a';
	bool dot=false;
	long long pre=0,cnt=0,ans=0;
	for(int i=0;s[i];i++){
		if(isalpha(s[i])){
			if(dot&&cnt<3) ans+=pre;
			else ans+=pre*100;
			dot=false;
			cnt=0;
			pre=0;
		}
		else if(s[i]=='.'){
			dot=true;
			cnt=0;
		}
		else{
			pre=pre*10+(s[i]-'0');
			cnt++;
		}		
	}
	if(ans==0){
		printf("%d\n",0);
		exit(0);
	}
	long long a[4];
	a[3]=100;
	for(int i=2;i>=0;i--) a[i]=a[i+1]*1000;
	bool fst=false;
	for(int i=0;i<4;i++){
		if(fst||ans/a[i]||i==3&&ans%100){
			if(fst) printf("%03lld",ans/a[i]);
			else printf("%lld",ans/a[i]);
			ans%=a[i];
			fst=true;
			if(i<3||i==3&&ans%100) printf(".");
		}
		
	}
	if(ans%100) printf("%02lld",ans%100);
	puts("");
	return 0;
}