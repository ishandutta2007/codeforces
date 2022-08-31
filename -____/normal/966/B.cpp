//CF 966B
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 333333;
int n,x,y;
pair<int,int> p[N];
LL s[N];
vector<int> v1,v2;
int main()
{
	int i,j,k;
	scanf("%d%d%d",&n,&x,&y);
	for(i=1;i<=n;i=i+1){
		scanf("%d",&j);
		p[i]=make_pair(j,i);
	}
	sort(p+1,p+n+1);
	reverse(p+1,p+n+1);
	for(i=1;i<=n;i=i+1)
		s[i]=(LL)p[i].first*i;
	for(i=1;i<=n;i=i+1)
		s[i]=max(s[i],s[i-1]);
	for(k=0;k<2;k=k+1){
		if(k)
			swap(x,y);
		for(i=1,j=1;i<=n;i=i+1){
			while(j<n&&(LL)p[j+1].first*i>=y){
				j++;
			}
			if((LL)p[j].first*i>=(LL)y&&i<j){
				if((LL)s[j-i]>=(LL)x){
					i=j-i;
					while(j>i){
						v2.push_back(p[j].second);
						j--;
					}
					for(j=1;j<=i;j=j+1){
						v1.push_back(p[j].second);
						if((LL)s[j]>=(LL)x)
							break;
					}
					break;
				}
			}
		}
		if(k)
			swap(v1,v2);
		if(i>n)
			continue;
		printf("Yes\n%d %d\n",v1.size(),v2.size());
		for(i=v1.size()-1;i>=0;i=i-1)
			printf("%d ",v1[i]);
		printf("\n");
		for(i=v2.size()-1;i>=0;i=i-1)
			printf("%d ",v2[i]);
		return 0;
	}
	printf("No\n");
	return 0;
}