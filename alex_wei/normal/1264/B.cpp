#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[4],b[4],pa[100005];
void run(int pos){
	for(int i=1;i<=a[0]+a[1]+a[2]+a[3];i++){
		b[pos]--;
		pa[i]=pos;
//		cout<<pos<<" ";
		if(i==a[0]+a[1]+a[2]+a[3])break;
		if(pos==0){
			if(!b[1])return;
			pos++;
		}
		else if(pos==1){
			if(b[0])pos--;
			else if(b[2])pos++;
			else return;
		}
		else if(pos==2){
			if(b[1])pos--;
			else if(b[3])pos++;
			else return;
		}
		else{
			if(!b[2])return;
			pos--;
		}
	}
	cout<<"YES\n";
	for(int i=1;i<=a[0]+a[1]+a[2]+a[3];i++)
		cout<<pa[i]<<" ";
	exit(0); 
}
int main(){
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	b[0]=a[0],b[1]=a[1],b[2]=a[2],b[3]=a[3];
	if(b[0])run(0);
//	cout<<endl;
	b[0]=a[0],b[1]=a[1],b[2]=a[2],b[3]=a[3];
	if(b[1])run(1);
	b[0]=a[0],b[1]=a[1],b[2]=a[2],b[3]=a[3];
	if(b[2])run(2);
	b[0]=a[0],b[1]=a[1],b[2]=a[2],b[3]=a[3];
	if(b[3])run(3);
	cout<<"NO\n";
    return 0;
}