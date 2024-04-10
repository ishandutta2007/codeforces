#include <stdio.h>

int n,m;
char str[600][600];
bool chk[600][600];

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) {
		scanf("%s",str[i]);
	}

	bool flag= true;
	bool first = true;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(str[i][j]=='X') {
				if(!first) {
					if(!chk[i][j]) flag=false;
					continue;
				}
				int y,x;
				for(y=i;y<n;y++) {
					if(str[y][j]=='.') break;
				}
				for(x=j;x<m;x++) {
					if(str[i][x]!='X') break;
					for(int k=i;k<y;k++) {
						if(str[k][x] != 'X') {
							flag= false;
							break;
						}
						chk[k][x] = true;
					}
				}
				first = false;
			}
		}
	}

	if(flag) printf("YES\n");
	else printf("NO\n");

	return 0;
}