#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int n,n1,n2;
double a[N],s;
int main(){
	cin>>n>>n1>>n2;
	if(n1>n2)swap(n1,n2);
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>n-n1-n2;i--)s+=a[i]/(i>n-n1?n1:n2);
	printf("%.10lf\n",s);
    return 0;
}