#include<bits/stdc++.h>
using namespace std;
char s[4][4];
void check()
{
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(s[i][j]=='x')
				for(int k=-1;k<2;k++)
					for(int l=-1;l<2;l++)
						if((k!=0||l!=0)&&i+k+k>-1&&i+k+k<4&&j+l+l>-1&&j+l+l<4&&s[i+k][j+l]=='x'&&s[i+k+k][j+l+l]=='x')
							cout<<"YES",exit(0);
}
int main()
{
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			cin>>s[i][j];
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(s[i][j]=='.')
				s[i][j]='x',check(),s[i][j]='.';
	cout<<"NO";
    return 0;
}