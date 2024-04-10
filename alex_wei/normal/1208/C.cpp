#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,c[4][4]={{8,9,1,13},{3,12,7,5},{0,2,4,11},{6,10,15,14}},ans[1002][1002];
int main()
{
	cin>>n;
	for(int i=0;i<n/4;i++)
		for(int j=0;j<n/4;j++){
			for(int k=0;k<4;k++)
				for(int l=0;l<4;l++)
					ans[i*4+k][j*4+l]=c[k][l]+(i*n/4+j)*16;
		}
	for(int i=0;i<n;i++){
		int cnt=0;
		for(int j=0;j<n;j++){
			cnt=cnt^ans[i][j];
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
//		cout<<cnt<<endl;
	}
    return 0;
}