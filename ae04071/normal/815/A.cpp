#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

typedef std::pair<int, int> ip;

int n,m;
int arr[100][100];

int main() {
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&arr[i][j]);
	
	bool flag=false;
	if(n>m) {
		int tmp[100][100];
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) tmp[j][i]=arr[i][j];
		std::swap(n,m);
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) arr[i][j]=tmp[i][j];
		flag=true;
	}

	int cnt=0;
	std::vector<ip> r,c;
	for(int i=0;i<n;i++) {
		int min=5000;
		for(int j=0;j<m;j++) if(arr[i][j]<min)min=arr[i][j];
		for(int j=0;j<m;j++) arr[i][j]-=min;
		if(min!=0)r.push_back(ip(i,min));
		cnt+=min;
	}
	for(int j=0;j<m;j++) {
		int min=5000;
		for(int i=0;i<n;i++) if(arr[i][j]<min)min=arr[i][j];
		for(int i=0;i<n;i++) arr[i][j]-=min;
		for(int i=0;i<n;i++) if(arr[i][j]!=0) {
			printf("-1\n");
			return 0;
		}
		if(min!=0)c.push_back(ip(j,min));
		cnt+=min;
	}
	printf("%d\n",cnt);

	for(auto &it:r) for(int i=0;i<it.second;i++) printf("%s %d\n",(flag?"col":"row"),it.first+1);
	for(auto &it:c) for(int i=0;i<it.second;i++) printf("%s %d\n",(flag?"row":"col"),it.first+1);

	return 0;
}