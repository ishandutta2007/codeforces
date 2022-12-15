#include <stdio.h>
#include <cstring>
#include <string>

int n;
char str[110];

int res[4];

char GetCh(int num)
{
	if(num==0) return 'R';
	else if(num==1) return 'B';
	else if(num==2) return 'Y';
	else return 'G';
}

int GetNum(char ch)
{
	if(ch=='R') return 0;
	else if(ch=='B') return 1;
	else if(ch=='Y') return 2;
	else return 3;
}

void Check(std::string tmp)
{
	int j=0;
	for(int i=0;i<n-4;i++) {
		for(int k=0;k<4;k++) {
			if(str[i+k] !='!' && str[i+k]!=tmp[(j+k)%4])
				return;
		}
		j++;
	}

	j=0;
	for(int i=0;i<n;i++) {
		if(str[i]=='!') {
			res[GetNum(tmp[j])]++;
		}
		j++;
		j%=4;
	}
}

void Make(int state, std::string str)
{
	if(state==(1<<4)-1) {
		Check(str);
	}

	for(int i=0;i<4;i++) {
		if(!(state & (1<<i))) {
			std::string tmp=str;
			tmp.push_back(GetCh(i));
			Make(state | (1<<i), tmp);
		}
	}
}

int main()
{
	scanf("%s",str);
	n=strlen(str);

	Make(0,"");
	for(int i=0;i<4;i++)
		printf("%d ",res[i]);

	return 0;
}