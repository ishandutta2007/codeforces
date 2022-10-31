#include<cstdio>
using namespace std;
int main(){
	int i,j,k;
	char s[200];
	scanf("%s",s);
	for(i=0;s[i];i++){
		if(s[i]=='0'||s[i]=='8'){
			printf("YES\n%c\n",s[i]);
			return 0;
		}
	}
	for(i=0;s[i];i++){
		if(s[i]=='0') continue;
		for(j=i+1;s[j];j++){
			if(((s[i]-'0')*10+(s[j]-'0'))%8==0){
				printf("YES\n%c%c\n",s[i],s[j]);
				return 0;
			}
		}
	}
	for(i=0;s[i];i++){
		for(j=i+1;s[j];j++){
			for(k=j+1;s[k];k++){
				if(((s[i]-'0')*100+(s[j]-'0')*10+(s[k]-'0'))%8==0){
					printf("YES\n%c%c%c\n",s[i],s[j],s[k]);
					return 0;
				}
			}
		}
	}
	puts("NO");
	return 0;
}