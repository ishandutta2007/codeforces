#include<bits/stdc++.h>
using namespace std;
int r1,r2,c1,c2,d1,d2; 
int main()
{
	cin>>r1>>r2>>c1>>c2>>d1>>d2;
	for(int i=1;i<10;i++)
		for(int j=1;j<10;j++)
			for(int k=1;k<10;k++)
				for(int l=1;l<10;l++)
					if(i!=j&&i!=k&&i!=l&&j!=k&&j!=l&&k!=l&&i+j==r1&&k+l==r2&&i+l==d1&&j+k==d2&&i+k==c1&&j+l==c2)
						cout<<i<<" "<<j<<"\n"<<k<<" "<<l,exit(0);
	cout<<-1;
}