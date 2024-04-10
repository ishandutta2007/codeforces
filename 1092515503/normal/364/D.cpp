/*
Solution:
we can get a random index,and find the GCD of that index with other indexes.
It's clear that a number smaller than 10^12 has at most 6000 divisors.
and we can O(6000^2)check if the divisor has enough multiples which is also a GCD.
if we do it for 10 times, the probability of a wrong answer is 2^-10. 
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1001000],ans;
map<int,int>mp;
vector<pair<int,int> >v; 
inline int calc(int x){
	mp.clear(),v.clear();
	for(register int i=1;i<=n;i++)mp[__gcd(a[i],a[x])]++;
	for(register auto x:mp)v.push_back(x);
	for(register int i=v.size()-1;i>=0;i--){
		if(v[i].first<=ans)break;
		register int res=0;
		for(register int j=i;j<v.size()&&(res*2<n);j++)if(!(v[j].first%v[i].first))res+=v[j].second;
		if(res*2>=n)return v[i].first;
	}
	return 0;
}
inline void read(int &x){
	x=0;
	register char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
inline void print(int x){
	if(x<=9)putchar('0'+x);
	else print(x/10),putchar('0'+x%10);
}
signed main(){
	read(n),srand(time(0));
	for(register int i=1;i<=n;i++)read(a[i]);
	for(register int i=1;i<=12;i++)ans=max(ans,calc((1ll*rand()*RAND_MAX+rand())%n+1));
	print(ans);
	return 0;
}