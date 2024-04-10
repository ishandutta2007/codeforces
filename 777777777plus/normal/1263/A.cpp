#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int c[3];

int main(){
	cin>>T;
	while(T--){
		cin>>c[0]>>c[1]>>c[2];
		sort(c,c+3);
		reverse(c,c+3);
		if(c[0]>c[1]+c[2])cout<<c[1]+c[2]<<endl;
		else cout<<(c[0]+c[1]+c[2])/2<<endl;
	}
}