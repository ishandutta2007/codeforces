#include<cstdio>
#include<vector>
#include<algorithm>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		std::vector<int>x(n);
		for(int &i:x)scanf("%d",&i);
		for(int j=0;x.size()>1;){
			std::vector<int>y;
			if(j)y.push_back(x[0]),--j;
			for(int i=0;i+1<x.size();++i)y.push_back(x[i+1]-x[i]);
			std::sort(y.begin(),y.end());
			x.clear();
			for(int i:y)
				if(i)x.push_back(i);
				else ++j;
		}
		if(x.empty())puts("0");
		else printf("%d\n",x.front());
	}
	return 0;
}