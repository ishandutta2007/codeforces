#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
int n,rem[N],c,r[N],ans;
char s[N]; 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>r[i];
		if(s[i]=='+')rem[r[i]]=1,c++;
		else if(rem[r[i]])rem[r[i]]=0,c--;
	}
	for(int i=n;i>0;i--){
		ans=max(ans,c);
		if(s[i]=='+')rem[r[i]]=0,c--;
		else if(s[i]=='-')rem[r[i]]=1,c++;
	}
	cout<<max(ans,c);
    return 0;
}