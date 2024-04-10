#include<bits/stdc++.h>
using namespace std;
int n,x[1003],y[1003];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		scanf("%d%d",x+i,y+i);
	while(1){
		vector<int>v[2];
		for(int i=0;i<n;i++)
			v[x[i]+y[i]&1].push_back(i);
		if(v[0].size()&&v[1].size()){
			cout<<v[0].size()<<endl;
			for(int i=0;i<v[0].size();i++)
				cout<<v[0][i]+1<<' ';
			return 0;
		}
		for(int i=0;i<n;i++){
			if((x[i]+y[i])&1)y[i]++;
			int a=x[i],b=y[i];
			x[i]=(a+b)/2;
			y[i]=(a-b)/2;
		}
	}
}