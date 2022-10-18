#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

string a,b,c;
int cnt[52];

int main()
{jizz
	int n,mx[3]={0,0,0},w;
	string ans[3]={"Kuro","Shiro","Katie"};
	cin >> n >> a >> b >> c;
	for(char x:a)
		if(x>='a'&&x<='z') ++cnt[x-'a'];
		else ++cnt[x-'A'+26];
	mx[0]=*max_element(cnt,cnt+52),MEM(cnt,0);
	for(char x:b)
		if(x>='a'&&x<='z') ++cnt[x-'a'];
		else ++cnt[x-'A'+26];
	mx[1]=*max_element(cnt,cnt+52),MEM(cnt,0);
	for(char x:c)
		if(x>='a'&&x<='z') ++cnt[x-'a'];
		else ++cnt[x-'A'+26];
	mx[2]=*max_element(cnt,cnt+52);
	if(mx[0]==a.size()&&a.size()!=1)
		if(n==1) mx[0]=a.size()-1;
		else mx[0]=a.size();
	else
		if(n>=a.size()-mx[0])
			mx[0]=a.size();
		else
			mx[0]+=n;
	if(mx[1]==a.size()&&a.size()!=1)
		if(n==1) mx[1]=a.size()-1;
		else mx[1]=a.size();
	else
		if(n>=a.size()-mx[1])
			mx[1]=a.size();
		else
			mx[1]+=n;
	if(mx[2]==a.size()&&a.size()!=1)
		if(n==1) mx[2]=a.size()-1;
		else mx[2]=a.size();
	else
		if(n>=a.size()-mx[2])
			mx[2]=a.size();
		else
			mx[2]+=n;
	w=max_element(mx,mx+3)-mx;
	if((mx[0]==mx[w]&&mx[1]==mx[w])||(mx[2]==mx[w]&&mx[1]==mx[w])||(mx[0]==mx[w]&&mx[2]==mx[w]))
		cout << "Draw\n";
	else 
		cout << ans[w] << "\n",0;
}