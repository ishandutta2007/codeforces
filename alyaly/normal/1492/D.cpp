#include<bits/stdc++.h>
#define int long long
#define N 300000
using namespace std;
int a,b,k;
signed main(){
	cin>>a>>b>>k;b--;
	if(k==0){ 
		cout<<"Yes"<<endl;
		for(int i=1;i<=b+1;i++)printf("1");for(int i=1;i<=a;i++)printf("0");printf("\n");
		for(int i=1;i<=b+1;i++)printf("1");for(int i=1;i<=a;i++)printf("0");printf("\n");
		return 0;
	}
	if(k>a+b-1||!a||!b)cout<<"No"<<endl;
	else{
		cout<<"Yes"<<endl;
		if(k<=b){
			printf("1");
			for(int i=1;i<=b;i++)printf("1");for(int i=1;i<=a;i++)printf("0");printf("\n");
			printf("1");
			for(int i=1;i<=b-k;i++)printf("1");
			printf("0");
			for(int i=1;i<=k;i++)printf("1");
			for(int i=1;i<a;i++)printf("0");
		}else if(k<=a){
			printf("1");
			for(int i=1;i<=b;i++)printf("1");
			for(int i=1;i<=a;i++)printf("0");
			printf("\n");
			printf("1");
			for(int i=1;i<=k;i++)printf("0");
			for(int i=1;i<=b;i++)printf("1");
			for(int i=1;i<=a-k;i++)printf("0");
			printf("\n");
		}else{
			printf("1");
			for(int i=1;i<=b;i++)printf("1");
			for(int i=1;i<=a;i++)printf("0");
			printf("\n");
			printf("1");
			printf("0");
			for(int i=1;i<b;i++)printf("1");
			for(int i=1;i<a-(a+b-1-k);i++)printf("0");
			printf("1");
			for(int i=1;i<=(a+b-1-k);i++)printf("0");
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}