#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define mp make_pair
#define maxn 1005
using namespace std;
const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
typedef long long ll;
typedef pair<int,int> P;
int n;
int a[maxn],b[maxn],cnt[maxn];
vector <int> app,disapp,nodes[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&a[i],&b[i]);
		cnt[a[i]]++;
	}
	for(int i=1;i<n;i++){
		if(b[i] != n){
			puts("NO");
			return 0;
		}
	}
	for(int i=1;i<n;i++){
		if(cnt[i] != 0) app.push_back(i);
		else disapp.push_back(i);
	}
	int j = 0;
	
//	for(int i=1;i<n;i++) cout << cnt[i] <<" ";
//	cout << endl;
//	system("pause");
	
	for(int i=1;i<n;i++){
		if(cnt[i] == 0) continue;
		for(int k=cnt[i] - 1;k>=1;k--){
			if(disapp[j] > i){
				puts("NO");
				return 0;
			}else{
				nodes[i].push_back(disapp[j++]);
			}
		}
	}
	puts("YES");
	for(int i=0;i<app.size();i++){
		int u = app[i];
		if(nodes[u].size() == 0) printf("%d %d\n",n,u);
		else if(nodes[u].size() == 1){
			printf("%d %d\n",n,nodes[u][0]);
			printf("%d %d\n",nodes[u][0],u);
		}else{
			printf("%d %d\n",n,nodes[u][0]);
			for(int j=0;j<nodes[u].size() - 1;j++){
				printf("%d %d\n",nodes[u][j],nodes[u][j + 1]);
			}
			printf("%d %d\n",nodes[u][cnt[u] - 2],u);
		}
	}
	return 0;
}