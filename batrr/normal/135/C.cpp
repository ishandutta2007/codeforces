// Tima the best
#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=2e5+123,inf=1e18,mod=1e9+7;
int cz,co,cq;
string s;
int get(int x,int y){
	int z=min(x,y)-1;
	x-=z,y-=z;
	while(x+y!=2){
	
		if(x==0)
			y--;
		else
			x--;
		
		if(x+y==2)
			break;
		
		if(y==0)
			x--;
		else
			y--;
		
		if(x+y==2)
			break;
		
		if(x==0){
			y=2;
			break;
		}
		if(y==0){
			x=2;
			break;
		}
	
	}            
	if(x==0)
		return 0;
	if(x==y)
		return 1;
	if(y==0)
		return 2;
}
int main(){
	/*
	1 0 1 0

	*/
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')
			cz++;
		if(s[i]=='1')
			co++;
		if(s[i]=='?')
			cq++;
	}                    
	//00
	if(get(co,cz+cq)==0)
		cout<<"00"<<endl;
	//01
	for(int x=0;x<=cq;x++){
		if( get(co+x,cz+cq-x)==1){
			if(s[s.size()-1]=='1'){
				cout<<"01"<<endl;
				break;
			}
			if(s[s.size()-1]!='0' && x!=0){
				cout<<"01"<<endl;
				break;
			}
		}
	}
	//10
	for(int x=0;x<=cq;x++){
		if( get(co+x,cz+cq-x)==1){
			if(s[s.size()-1]=='0'){
				cout<<"10"<<endl;
				break;
			}
			if(s[s.size()-1]!='1' && x!=cq){
				cout<<"10"<<endl;
				break;
			}
		}
	}
	
	//11
	if(get(co+cq,cz)==2)
		cout<<"11"<<endl;

}