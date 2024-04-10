#include <stdio.h>

const int dy[8]={-1,-1,-1,0,0,1,1,1};
const int dx[8]={-1,0,1,-1,1,-1,0,1};

char arr[4][5];

int Go(int y, int x)
{
	if(y<0||x<0||y>=4||x>=4||arr[y][x]=='o') return 8;
	else if(arr[y][x]=='.') return 1;
	else return 0;
}

bool Check(int y, int x)
{
	for(int k=0;k<4;k++) {
		int cnt=0;
		if(arr[y][x]!='x') cnt++;

		int cy=y+dy[k], cx=x+dx[k];
		cnt+=Go(cy,cx);
		cy=y+dy[8-k-1]; cx=x+dx[8-k-1];
		cnt+=Go(cy,cx);
		if(cnt<=1) return true;
	}
	return false;
}

int main()
{
	for(int i=0;i<4;i++)
		scanf("%s",arr[i]);

	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++) {
			if(arr[i][j]=='o') continue;
			if(Check(i,j))
				{
					printf("YES\n");
					return 0;
				}
		}
	}

	printf("NO\n");

	return 0;
}