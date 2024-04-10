#include<cstdio>
#include<vector>
using namespace std;
int main(){
	int n,i;
	long long m;
	vector<int> l,r;
	scanf("%d%I64d",&n,&m);
	m--;
	for(i=n-1;i>0;i--){
		if(m&(1LL<<i-1)) r.push_back(n-i);
		else l.push_back(n-i);
	}
	l.push_back(n);
	bool first=true;
	for(i=0;i<l.size();i++){
		if(first){
			first=false;
		}
		else{
			putchar(' ');
		}
		printf("%d",l[i]);
	}
	for(i=r.size()-1;i>=0;i--){
		if(first){
			first=false;
		}
		else{
			putchar(' ');
		}
		printf("%d",r[i]);
	}
	putchar('\n');
	return 0;
}