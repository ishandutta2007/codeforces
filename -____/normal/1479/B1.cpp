#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 111111;
int n,a[N],s,l,r;
vector<int> v;
void go(int x){
	r=x;
	if(l&&r&&l==r){
		int i,o;
		o=1;
		for(i=0;i+1<v.size();i=i+1)
			if(v[i]!=l&&v[i+1]!=l)
				o=0;
		s-=o;
	}
	l=r;
	v.clear();
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	i=1;
	while(i<=n){
		if(a[i]==a[i+1]){
			s+=2;
			go(a[i]);
			while(a[i]==a[i+1])
				i++;
		}
		else{
			s++;
			v.push_back(a[i]);
		}
		i++;
	}
	go(0);
	printf("%d",s);
	return 0;
}