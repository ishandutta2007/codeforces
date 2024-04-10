#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t;
int main(){
	cin>>t;
	while(t--){
		string a,b,c;
		cin>>a>>b>>c;
		for(int i=0;i<a.size();i++){
			if(a[i]!=b[i]){
				if(c[i]==a[i])swap(c[i],b[i]);
				else if(c[i]==b[i])swap(c[i],a[i]);
			}
			else swap(a[i],c[i]);
		}
		if(a==b)puts("YES");
		else puts("NO");
	}
    return 0;
}