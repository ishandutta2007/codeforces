#include<cstdio>
#include<vector>
#define N 100100
using namespace std;
char s[N];
int add[N];
int main(){
	int i,j,l,cnt=0;
	bool flag=false;
	vector<int> v;
	scanf("%s",s);
	l=0;
	for(i=0;s[i];i++){
		if(s[i]=='(') l++;
		else if(s[i]==')') l--;
		else cnt++;
	}
	for(i=0;i<cnt-1;i++){
		add[i]=1;
		l--;
	}
	if(l<1) printf("-1\n");
	else{
		add[cnt-1]=l;
		j=0;
		l=0;
		for(i=0;s[i];i++){
			if(s[i]=='(') l++;
			else if(s[i]==')') l--;
			else l-=add[j++];
			if(l<0) flag=true;
		}
		if(flag) printf("-1\n");
		else{
			for(i=0;i<cnt;i++) printf("%d\n",add[i]);
		}
	}
	return 0;
}