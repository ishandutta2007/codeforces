#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int h[110];
void mainfun(){
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
		cin>>h[i];
	for(int i=0;i<n-1;i++){
		if(h[i+1]-h[i]>k)
			m-=h[i+1]-h[i]-k;
		else if(h[i+1]>k)
			m+=h[i]-h[i+1]+k;
		else m+=h[i];
		if(m<0){
			cout<<"NO"<<endl;
			return;
		} 
	}
	cout<<"YES"<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
		mainfun();
	return 0;
}