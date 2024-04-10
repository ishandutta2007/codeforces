#include<bits/stdc++.h>
using namespace std;
int main(){
	int l;
	long long ans=0;
	vector<int> val;
	vector<long long> mul;
	scanf("%d",&l);
	val.push_back(1);
	mul.push_back(1);
	string s;
	for(int i=0;i<l;i++){
		char t[100];
		int x;
		scanf("%s",t);
		if(t[0]=='f'){
			scanf("%d",&x);
			val.push_back(x);
			if(mul.back()<0 || mul.back()*x>=(1LL<<32)) mul.push_back(-1);
			else mul.push_back(mul.back()*x);
		}
		else if(t[0]=='e'){
			val.pop_back();
			mul.pop_back();
		}
		else{
			if(mul.back()<0||ans<0) ans=-1;
			else{
				ans+=mul.back();
				if(ans>=(1LL<<32)) ans=-1;
			}
		}
	}
	if(ans<0) puts("OVERFLOW!!!");
	else printf("%lld\n",ans);
	return 0;
}