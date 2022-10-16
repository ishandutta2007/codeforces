#include<bits/stdc++.h>
using namespace std;
int z,a[3][10],p;
int main()
{
	cin>>z;
	for(int i=0;i<z;i++)
		for(int j=0;j<6;j++)
			cin>>p,a[i][p]=1;
	for(int i=1;i<10;i++){
		int pd=1;
		for(int j=0;j<z;j++)
			if(a[j][i])
				pd=0;
		if(pd)cout<<i-1,exit(0);
	}
	for(int i=1;i<10;i++)
		for(int j=0;j<10;j++){
			int pd=1;
			for(int k=0;k<z;k++)
				for(int l=0;l<z;l++)
					if(k!=l&&a[k][i]&&a[l][j])
						pd=0;
			if(pd)cout<<i*10+j-1,exit(0);
		}
	for(int i=1;i<10;i++)
		for(int j=0;j<10;j++)
			for(int k=0;k<10;k++){
				int pd=1;
				for(int l=0;l<z;l++)
					for(int m=0;l<z;l++)
						for(int n=0;n<z;n++)
							if(l!=m&&m!=n&&l!=n&&a[l][i]&&a[m][j]&&a[n][k])
								pd=0;
				if(pd)cout<<i*100+j*10+k-1,exit(0);
			}
    return 0;
}