#include<bits/stdc++.h>
using namespace std;
char c[4][4];
int main()
{
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			cin>>c[i][j];
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			int sum=0;
			for(int k=0;k<2;k++)
				for(int l=0;l<2;l++)
					sum+=c[i+k][j+l]=='.';
			if(sum!=2)cout<<"YES",exit(0);
		}
	cout<<"NO";
    return 0;
}