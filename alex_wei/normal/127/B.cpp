#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e2+5;
int n,a[N],buc[N],ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],buc[a[i]]++;
	for(int i=1;i<=100;i++)ans+=buc[i]/2;
	cout<<ans/2;
    return 0;
}