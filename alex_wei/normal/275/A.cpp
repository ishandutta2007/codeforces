#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a,b[5][5]; 
int main()
{
	for(int i=1;i<4;i++)
		for(int j=1;j<4;j++){
			cin>>a;
//			cout<<a<<endl;
			if(a%2==0)continue;
			for(int k=-1;k<2;k++)
				for(int l=-1;l<2;l++)
					if(abs(k)+abs(l)<2)
						b[k+i][l+j]=!b[k+i][l+j];
		}
	for(int i=1;i<4;i++){
		for(int j=1;j<4;j++)
			cout<<!b[i][j];
		cout<<endl;
	}
	return 0;
}