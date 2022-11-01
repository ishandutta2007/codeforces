# include<iostream>
# include<string>
# include<vector>

using namespace std;
int a[4];
int main(){
	int n;
	cin>>n;
	
	int m;
	for (int i=0; i<n; i++){
		cin>> m;
		a[m-1] += 1;
	}
	int t = 0;
	t += a[3];
	t += a[1]/2;
	t += a[2];
	if (a[0] >= a[2]){
		a[0] -= a[2];
	}
	else{
		a[0] = 0;
	}
	a[1] = a[1]%2*2;
	if ((a[0]+a[1])%4 == 0){
		cout<< (a[0]+a[1])/4+t;
	}
	else{
		cout<< (a[0]+a[1])/4+t+1;
	}
}