#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,k,x,s=0,a;
    cin>>n>>k>>x;
    for(int i=0 ;i<n-k;i++){
		cin>>a;
		s+=a;
	}
    for(int i=n-k ;i<n;i++)s+=x;
    cout<<s;
}