#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
 	int r,c,s=0,i,j;
 	cin>>r>>c;
 	char a[r+1][c+1];
 	for(i=1;i<=r;i++)
 	{
	     a[i][0]=0;
	     for(j=1;j<=c;j++)
	     {
              cin>>a[i][j];
         }
    }
    for(i=1;i<=c;i++)a[0][i]=0;
	for(i=1;i<=r;i++)
	{
	 	 for(j=1;j<=c;j++)
		 {
		  	  if(a[i][j]=='S')a[i][0]=1,a[0][j]=1;
	     }
    }
	for(i=1;i<=r;i++)
	{
	 	 for(j=1;j<=c;j++)
		 {
		  	  if((a[i][0]==1)&&(a[0][j]))s++;
	     }
    }
	j=(r*c)-s;
	cout<<j<<endl; 	  	  
	//system("pause");
	//return 0;
}