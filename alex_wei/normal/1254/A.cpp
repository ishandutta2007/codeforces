#include<bits/stdc++.h>
using namespace std;
#define ll long long
int T,r,c,k;
char p[105][105],t[105][105];
int main()
{
	cin>>T;
	while(T--){
		cin>>r>>c>>k;
		int num=0,ec,rm,x=1,y=1;
		char q='0';
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				cin>>p[i][j],num+=p[i][j]=='R';
		ec=num/k;
		rm=num%k;
		for(int i=1;i<=k;i++){
			int ned=ec+(i<=rm);
			while((ned||i==k)&&x<=r){
				t[x][y]=q;
				if(p[x][y]=='R')ned--;
				if(x%2){
					y++;
					if(y>c)x++,y=c;
				}
				else{
					y--;
					if(y<1)x++,y=1;
				}
			}
			q++;
			if(q==('9'+1))q='A';
			else if(q==('Z'+1))q='a';
		}
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++)
				cout<<t[i][j];
			cout<<endl;
		}
	}
    return 0;
}