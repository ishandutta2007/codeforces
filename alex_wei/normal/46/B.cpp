#include<bits/stdc++.h>
using namespace std;
map <string,int> c;
map <int,string> d;
int n[5],k;
int main()
{
	c["S"]=0,c["M"]=1,c["L"]=2,c["XL"]=3,c["XXL"]=4;
	d[0]="S",d[1]="M",d[2]="L",d[3]="XL",d[4]="XXL";
	for(int i=0;i<5;i++)cin>>n[i];
	cin>>k;
	for(int i=0;i<k;i++){
		string p;
		cin>>p;
		int l=c[p];
		for(int j=0;j<5;j++){ 
			if(l+j<5&&n[l+j]){cout<<d[l+j]<<endl;n[l+j]--;break;}
			if(l-j>-1&&n[l-j]){cout<<d[l-j]<<endl;n[l-j]--;break;}
		}
	}
	return 0;
}