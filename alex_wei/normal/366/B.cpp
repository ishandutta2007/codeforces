#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int a,n,p[N],k;
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a,p[i%k]+=a;
	int pos=0;
	for(int i=0;i<k;i++)if(p[i]<p[pos])pos=i;
	cout<<pos+1<<endl;
    return 0;
}