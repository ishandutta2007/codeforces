#include<cstdio>
#include<algorithm>
#define N 1001000
#define C 514
#define Q 1000000007
using namespace std;
char s1[N],s2[N];
char rev[128];
bool check(int n){
	int mul=1,h1=0,h2=0;
	for(int i=n-1;i>=0;i--){
		h1=(1LL*h1*C+s1[i])%Q;
		h2=(1LL*s2[i]*mul+h2)%Q;
		mul=1LL*mul*C%Q;
		if(h1==h2){
			bool sm=true;
			for(int j=n-1;j>=i;j--){
				if(s1[j]!=s2[n-1+i-j]){
					sm=false;
					break;
				}
			}
			if(sm){
				return true;
			}
		}
	}
	return false;
}
int main(){
	int n;
	bool flag=true;
	scanf("%d",&n);
	n--;
	scanf("%s%s",s1,s2);
	rev['S']='N';
	rev['W']='E';
	rev['N']='S';
	rev['E']='W';
	for(int i=0;i<n;i++){
		s2[i]=rev[s2[i]];
	}
	if(check(n)){
		puts("NO");
	}
	else{
		puts("YES");
	}
	return 0;
}