#include<bits/stdc++.h>
using namespace std;
#define ll long long
int r,c,pd;
ll p[505][505];
int main(){
	cin>>r>>c;
	if(r==1&&c==1){
		cout<<'0';
		exit(0);
	}
	if(r>c)swap(r,c),pd=1;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			p[i][j]=i;
	for(int j=1;j<=c;j++)
		for(int i=1;i<=r;i++)
			p[i][j]*=j+r;
	if(!pd){
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++)
				cout<<p[i][j]<<" ";
			cout<<endl;
		}
	}
	else{
		for(int j=1;j<=c;j++){
			for(int i=1;i<=r;i++)
				cout<<p[i][j]<<" ";
			cout<<endl;
		}
	}
    return 0;
}