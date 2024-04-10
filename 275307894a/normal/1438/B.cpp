#include<cstdio>
#include<map>
using namespace std;
int n,m,k,x,y,z,t,flag;
map<int,int> s;
int main(){
	scanf("%d",&t);
	while(t--){
		flag=0;
		scanf("%d",&n);
		while(n--){
			scanf("%d",&x);
			if(s[x]) flag=1;
			s[x]=1;
		} 
		if(flag) printf("YES\n");
		else printf("NO\n");
		s.clear();
	}
}