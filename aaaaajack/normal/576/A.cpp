#include<cstdio>
#include<vector>
#define N 1010
using namespace std;
bool notp[N];
int main(){
	int n;
	vector<int> v;
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		if(!notp[i]){
			for(int j=i;j<=n;j*=i){
				v.push_back(j);
			}
		}
		for(int j=2;i*j<=n;j++){
			notp[i*j]=true;
		}
	}
	printf("%d\n",(int)v.size());
	for(int i=0;i<v.size();i++) printf("%d ",v[i]);
	return 0;
}