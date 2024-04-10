#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

ll k;
char s[]={"codeforces"};

int main(){
	cin>>k;
	ll ans=1;
	for(int i=1;i<=100;++i){
		ll k1=1;
		for(int j=1;j<=10;++j)k1*=i;
		if(k1>=k){
			int tot=10;
			for(int j=1;j<=10;++j)
			if(k1/i*(i-1)>=k){
				k1=k1/i*(i-1);
				tot--;
			}
			for(int j=1;j<=10;++j)
			if(j<=tot){
				for(int k=1;k<=i;++k)printf("%c",s[j-1]);
			}
			else{
				for(int k=1;k<=i-1;++k)printf("%c",s[j-1]);
			}
			break;
		}
	}
}