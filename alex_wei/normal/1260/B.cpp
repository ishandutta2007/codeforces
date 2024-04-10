#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,a,b;
int main()
{
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(a*2<b||b*2<a)puts("NO");
		else{
			if(a==b&&a%3)puts("NO");
			else{
				if(a<b)swap(a,b);
				int dif=a-b;
				a-=dif<<1,b-=dif;
				if(a%3)puts("NO");
				else puts("YES"); 
			}
		}
	}
    return 0;
}