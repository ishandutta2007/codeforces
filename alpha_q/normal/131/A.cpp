#include <stdio.h>

int main(void) {
	char ch[110];
	scanf("%s", ch);
	
	int i,j,l,f=0;
	
	for(i=0;ch[i]!='\0';i++){}
	
		// small
	if(ch[0]>96){
		l=1;
		for(j=1;ch[j]!='\0';j++){
			if(ch[j]<97)l++;
			else break;
		}
		if(l==i){
			f=1;
			printf("%c", ch[0]-32);
			for(i=1;ch[i]!='\0';i++)printf("%c", ch[i]+32);
			printf("\n");
		}
	}
	else if(ch[0]<97){
		l=1;
		for(j=1;ch[j]!='\0';j++){
			if(ch[j]<97)l++;
			else break;
		}
		if(l==i){
			f=1;
			for(i=0;ch[i]!='\0';i++)printf("%c", ch[i]+32);
			printf("\n");
		}
	}
	if(f==0)printf("%s\n", ch);
	
	return 0;
}