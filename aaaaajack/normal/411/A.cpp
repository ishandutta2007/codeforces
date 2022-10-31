#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
int main(){
	char s[200];
	int len,i;
	bool up=false,low=false,num=false;
	scanf("%s",s);
	len=strlen(s);
	for(i=0;i<len;i++){
		if(isdigit(s[i])) num=true;
		else if(islower(s[i])) low=true;
		else if(isupper(s[i])) up=true;
	}
	if(up&&low&&num&&len>=5) puts("Correct");
	else puts("Too weak");
	return 0;
}