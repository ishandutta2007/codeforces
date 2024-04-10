#include <stdio.h>
#include <cstring>
int n;
char str[30];

int main() {
	scanf("%d",&n);
	int sum=0;
	for(int i=0;i<n;i++) {
		scanf("%s",str);
		if(!strcmp(str,"Tetrahedron"))
			sum+=4;
		else if(!strcmp(str,"Cube"))
			sum+=6;
		else if(!strcmp(str,"Octahedron"))
			sum+=8;
		else if(!strcmp(str, "Dodecahedron"))
			sum+=12;
		else if(!strcmp(str, "Icosahedron"))
			sum+=20;
	}
	printf("%d\n",sum);
	return 0;
}