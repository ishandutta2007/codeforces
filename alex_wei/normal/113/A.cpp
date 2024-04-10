#include<bits/stdc++.h>
using namespace std;
string s[3][2]={{"lios","liala"},{"etr","etra"},{"initis","inites"}},t[50002];
int c,p[50002],q[50002],n,ad,v;
int main()
{
	while(cin>>t[++c]){
		q[c]=2;
		for(int i=0;i<3;i++)
			for(int j=0;j<2;j++){
				if(t[c].size()<s[i][j].size())continue;
				int pd=1;
				for(int k=0;k<s[i][j].size();k++)
					if(t[c][t[c].size()-s[i][j].size()+k]!=s[i][j][k])pd=0;
				if(pd)p[c]=i,q[c]=j;
			}
	}
	for(int i=1;i<c;i++){
		if((q[i]!=q[i-1]||p[i]<p[i-1]||p[i]-p[i-1]>1)&&i>1||q[i]==2)cout<<"NO",exit(0);
		!p[i]?ad++:(p[i]<2?n++:v++);
	}
	cout<<(n>1||(n==0&&(ad>1||v>1))?"NO":"YES");
	return 0; 
}