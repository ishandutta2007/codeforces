#include<bits/stdc++.h>
using namespace std;
#define ld long double
map <ld,bool> mp;
int n,a,b,c,d,cnt;
void add(ld a,ld b){ld r=a==0?1e9:b/a;cnt+=!mp[r];mp[r]=1;}
int main(){
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)cin>>c>>d,add(c-a,d-b);
	cout<<cnt;
	return 0;
}