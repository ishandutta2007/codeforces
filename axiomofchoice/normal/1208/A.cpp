#include <bits/stdc++.h>
using namespace std;
#define ll long long
int N,a,b,n;
int main(){
	//ios_base::sync_with_stdio(false);
	cin>>N;
	for(int I=0;I<N;I++){
		cin>>a>>b>>n;
		n%=3;
		for(int i=0;i<n;i++){
			int c=a^b;
			a=b;
			b=c;
		}
		cout<<a<<endl;
	}
	return 0;
}