#include <stdio.h>
#include <vector>
#include <string>
#include <utility>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

typedef std::pair<string, string> sp;

int n,m;
string str[111];
sp arr[111];

int cache[111][111];
std::vector<int> space[111];
int con[111];
char tmp[150];

bool cmp(int a, int b)
{
	for(auto &it:space[a]) {
		int j=0;
		for(j=0;it+j<arr[a].second.size() && j<str[b].size();j++) {
			if(arr[a].second[it+j]!=str[b][j])
				break;
		}
		if(j==str[b].size()) {
			if(it+j==arr[a].second.size())
				return false;
			else if(arr[a].second[it+j]==' ' || arr[a].second[it+j]=='.' || arr[a].second[it+j]==','  || arr[a].second[it+j]=='?' || arr[a].second[it+j]=='!' )
				return false;
		}
	}
	return true;
}

int DP(int idx, int prev)
{
	if(idx>=m+1) return 1;

	int &ret=cache[idx][prev];
	if(ret!=-1) return ret;

	ret=0;
	for(int j=1;j<=n;j++) {
		if((arr[idx].first=="?" || arr[idx].first==str[j]) && j!=prev) {
			if(idx<m && arr[idx+1].first==str[j]) continue;
			if(cmp(idx, j)) {
				ret=DP(idx+1,j);
				if(ret==1){
					con[idx]=j;
					break;
				}
			}
			
		}
	}
	return ret;
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		memset(cache,-1,sizeof(cache));
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			scanf("%s",tmp);
			str[i].clear();
			str[i]=tmp;
		}
		scanf("%d",&m);
		getchar();
		for(int i=1;i<=m;i++) {
			space[i].clear();
			arr[i].first.clear();
			arr[i].second.clear();
			gets(tmp);
			int j=0, len=strlen(tmp);
			bool flag=true;
			for(j=0;j<len;j++) {
				if(tmp[j]==':') break;
				arr[i].first.push_back(tmp[j]);
			}
			int ori=j+1;
			space[i].push_back(j+1-ori);
			for(j=j+1;j<len;j++) {
				arr[i].second.push_back(tmp[j]);
				if(flag&&(tmp[j]!=' ' && tmp[j]!='.'&&tmp[j]!=','&&tmp[j]!='?'&&tmp[j]!='!'))  {
					flag=false;
					space[i].push_back(j-ori);
				}
				else if(!flag&&(tmp[j]==' ' || tmp[j]=='.'||tmp[j]==','||tmp[j]=='?'||tmp[j]=='!')) {
					flag=true;
					space[i].push_back(j-ori);
				}
			}
		}
		DP(1,0);
		if(cache[1][0]==0) printf("Impossible\n");
		else {
			for(int i=1;i<=m;i++) {
				std::cout << str[con[i]] << ":" << arr[i].second << std::endl;
			}
		}
	}
	return 0;
}