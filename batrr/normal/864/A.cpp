#include <iostream>
using namespace std;
int a,b;

int main(){
	int n,q=0,w=0,q1=0,w1=0;
	cin >>n;
	int a[n];
	for(int i= 0; i<n; i++){cin>>a[i];}
	q=a[0];
	for(int i= 1; i<n; i++){
		if(a[i]!=q){
			w=a[i];
			i=n;
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]==q){q1++;}
		if(a[i]==w){w1++;}
		if(a[i]!=q && a[i]!=w){cout<<"NO";return 0;}
		}
	if(q1==w1){
		cout<<"YES"<<endl<<q<<" "<<w;
		return 0;
	}
	cout<<"NO";
	return 0;
}