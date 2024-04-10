//CF 938F
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
const int N = 5005;
int n,k;
char ch[N],m;
bool ok[N][N];
queue<pair<int,int> > q;
int main()
{
	int i,j,l,o,t;
	scanf("%s",ch+1);
	ch[0]='_';
	n=strlen(ch)-1;
	i=2;
	while(i<=n){
		k++;
		i<<=1;
	}
	l=n-(1<<k)+1;
	ok[0][0]=1;
	for(o=0;o<l;o=o+1){
		m='z'+1;
		for(i=o;i+(l-o)<=n;i=i+1){
			j=i-o;
			if(ok[i][j]){
				m=min(m,ch[i+1]);
				for(t=0;t<k;t=t+1){
					if(j&(1<<t))
						continue;
					ok[i+(1<<t)][j|(1<<t)]=1;
				}
			}
		}
		cout<<m;
		for(i=o;i+(l-o)<=n;i=i+1){
			j=i-o;
			if(ok[i][j]){
				if(ch[i+1]==m)
					ok[i+1][j]=1;
			}
		}
	}
	return 0;
}