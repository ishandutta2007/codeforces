#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T;
ll n;
set<ll> s;
int main(){
	for(int i=1;i<=100000;++i)s.insert(i*4ll*i),s.insert(i*2ll*i);
	cin>>T;
	while(T--){
		cin>>n;
		if(s.count(n))puts("YES");
		else puts("NO");
	}
    return 0;
}