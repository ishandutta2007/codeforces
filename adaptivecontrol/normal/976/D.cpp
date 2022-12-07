#include<bits/stdc++.h>
using namespace std;
int n,d[303];
vector<int>a,b;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>d[i];
	int l=1,r=n;
	while(l<=r){
		for(int i=d[l-1]+1;i<=d[l];i++)
			for(int j=i+1;j<=d[r]+1;j++)
				a.push_back(i),
				b.push_back(j);
		l++;r--;
	}
	cout<<a.size()<<endl;
	for(int i=0;i<a.size();i++)
		cout<<a[i]<<' '<<b[i]<<endl;
}