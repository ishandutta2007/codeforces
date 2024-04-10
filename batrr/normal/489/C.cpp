#include <iostream>
#include <vector>
#include <set>
#define pb push_back
using namespace std;
const int maxn=1e6+123;
int sum,len,ans,sn,ln;
int main(){
	cin>>len>>sum;
	if(len == 1 && sum==0)
		cout<<"0 0";
	else if(sum == 0 || sum>len*9)
		cout<<"-1 -1";
	else{
		sn=sum;
		ln=len-1;
		for(int i=1;i<10;i++)
			if(ln*9>=sn-i){
				ans=i;
				sn-=i;
				cout<<i;
				break;
			}
		while(ln--){
			for(int i=0;i<=10;i++)
				if(sn-i<=ln*9){
					sn-=i;
					cout<<i;
					break;
				}
		}
		cout<<' ';
		ans=0;
		sn=sum;
		ln=len;
		while(ln!=0){
			for(int i=9;i>=0;i--)
				if(sn-i>=0){
					sn-=i;
					cout<<i;
					break;
				}
			ln--;
		}
	}
}