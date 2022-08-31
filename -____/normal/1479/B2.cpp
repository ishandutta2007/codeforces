#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 111111;
int n,a[N],s,p[N];
vector<pair<int,int> > v;
int main()
{
	int i,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	s=n;
	for(i=1;i<=n;i++){
		if(p[a[i]]){
			if(p[a[i]]==i-1)
				s--;
			else
				v.push_back(make_pair(i-1,p[a[i]]+1));
		}
		p[a[i]]=i;
	}
	sort(v.begin(),v.end());
	x=0;
	for(i=0;i<v.size();i++){
		if(x<v[i].second){
			x=v[i].first;
			s--;
		}
	}
	printf("%d",s);
	return 0;
}