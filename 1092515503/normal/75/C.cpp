#include<bits/stdc++.h>
using namespace std;
int a,b,q,t1,t2,gcd;
vector<int>v;
int main(){
	scanf("%d%d",&a,&b),gcd=__gcd(a,b);
	for(int i=1;i*i<=gcd;i++)if(!(gcd%i)){
		v.push_back(-i);
		if(i*i!=gcd)v.push_back(-gcd/i);
	}
	sort(v.begin(),v.end());
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&t1,&t2);
		vector<int>::iterator it=lower_bound(v.begin(),v.end(),-t2);
		if(it==v.end()||*it>-t1)puts("-1");
		else printf("%d\n",-*it);
	}
	return 0;
}