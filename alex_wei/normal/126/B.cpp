#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define NOWAY puts("Just a legend"),exit(0)
const ll b1=131,b2=37,m1=1e9+7,m2=998244353;
const int N=1e6+5;
ll f1[N],f2[N],pw1[N],pw2[N];
int ok[N],cnt,l;
string s;
int get1(int l,int r){
	return ((f1[r]-1ll*f1[l-1]*pw1[r-l+1])%m1+m1)%m1;
}
int get2(int l,int r){
	return ((f2[r]-1ll*f2[l-1]*pw2[r-l+1])%m2+m2)%m2;
}
bool check(int len){
	int num1=get1(1,len),num2=get2(1,len);
	for(int i=len+1;i<s.size();i++)
		if(num1==get1(i-len+1,i)&&num2==get2(i-len+1,i))
			return true;
	return false;
}
int ef(int l,int r){
	if(l==r)return l;
	int m=(l+r>>1)+1;
	if(check(ok[m]))return ef(m,r);
	else return ef(l,m-1);
}
int main()
{
	cin>>s,l=s.size();
	pw1[0]=pw2[0]=1;
	for(int i=1;i<=s.size();i++){
		int q=s[i-1]-'a';
		f1[i]=(f1[i-1]*b1+q)%m1;
		f2[i]=(f2[i-1]*b2+q)%m2;
		pw1[i]=pw1[i-1]*b1%m1;
		pw2[i]=pw2[i-1]*b2%m2;
	}
	for(int i=1;i<=s.size();i++)
		if(get1(1,i)==get1(l-i+1,l)&&get2(1,i)==get2(l-i+1,l))
			ok[++cnt]=i;
	if(!cnt||!check(ok[1]))NOWAY;
	cout<<s.substr(0,ok[ef(1,cnt)]);
	return 0;
}