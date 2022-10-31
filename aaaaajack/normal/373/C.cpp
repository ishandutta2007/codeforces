#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
bool can(int n,vector<int>& kan){
	int i;
	for(i=0;i<n;i++){
		if(kan[i]*2>kan[kan.size()-n+i]) return false;
	}
	return true;
}
int maxkan(int low,int up,vector<int>& kan){
	int m=(low+up)/2;
	if(up-low==1) return low;
	if(can(m,kan)) return maxkan(m,up,kan);
	else return maxkan(low,m,kan);
}
int main(){
	int n,i;
	vector<int> kan;
	scanf("%d",&n);
	kan.resize(n);
	for(i=0;i<n;i++) scanf("%d",&kan[i]);
	sort(kan.begin(),kan.end());
	printf("%d\n",n-maxkan(0,n/2+1,kan));
	return 0;
}