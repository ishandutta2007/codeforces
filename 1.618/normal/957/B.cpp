#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define maxn 55
#define pb push_back
using namespace std;
typedef long long ll;
bool checked[maxn];
char c[maxn][maxn];
int n,m;
vector <int> lis;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	memset(checked,false,sizeof(checked));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> c[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		if(checked[i]) continue;
		for(int k=i+1;k<=n;k++){
			bool same = true,explode = false;
			for(int j=1;j<=m;j++){
				if(c[i][j] != c[k][j]){
					same = false;
//					cout<<i<<" "<<j<<" "<<k<<endl;
//					system("pause");
				}
				if(c[i][j] == '#' && c[k][j] == '#') explode = true;
			}
			if(same) checked[k] = true;
			else if(explode){
				puts("No");
				return 0;
			}
		}
	}
	puts("Yes");
	return 0;
}