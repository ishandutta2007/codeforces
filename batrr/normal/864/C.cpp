#include <iostream>
using namespace std;
int a,b;

int main(){
	unsigned long a,b,g,f,k,n=0;
	cin>>a>>b>>f>>k;
	if(k>2){
	if(2*f>b || 2*(a-f)>b){
		cout<<-1; 
		return 0;
	}}
	if(k==2){
	if(f>b || 2*(a-f)>b){
		cout<<-1; 
		return 0;
	}}
	if(k==1){
	if(f>b || a-f>b){
		cout<<-1; 
		return 0;
	}}
	g=b-f;
	for(int i=2;i<2*k;i++){
		switch(i%4){
			case 0:
				if(g>=2*f){
					g=g-f;
				}else{
					n++;
					g=b-f;
				}
				break;
			case 1:
				g=g-f;break;
			case 2:
				if(g>=2*(a-f)){
					g=g-(a-f);
				}else{
					n++;
					g=b-(a-f);
				}
				break;
			case 3:
				g=g-(a-f);break;
		}
	}
	switch(2*k%4){
		case 0:
			if(g>=f){
			}else{
				n++;
			}
			break;
		case 2:
			if(g>=a-f){
			}else{
				n++;
			}
			break;
			}
 cout<<n;
 return 0;
}