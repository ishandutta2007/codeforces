#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e2+5;
int n,a[N];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<n;j++){
			if(a[j]>a[j+1])cout<<j<<" "<<j+1<<endl,swap(a[j],a[j+1]);
		}
	}
    return 0;
}