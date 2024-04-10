#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,pos,pd[205],len,tot;
string s;
char p;
int main(){
	cin>>n>>s;
	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)for(int k=j+1;k<n;k++)if(s[i]>s[j]&&s[j]>s[k])puts("NO"),exit(0);
	puts("YES");
	for(int i=0;i<n;i++){
		int p=0;
		for(int j=0;j<i;j++)if(s[j]>s[i])p=1;
		cout<<p;
	}
    return 0;
}