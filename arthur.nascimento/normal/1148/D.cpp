#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pip pair<int,pii>
#define pb push_back

bool compu(pip a,pip b){
	return a.second.second > b.second.second;
}

bool compd(pip a,pip b){
	return a.second.first < b.second.first;
}

main(){
	
	int n;
	scanf("%d",&n);
	vector<pip> up, down;
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a < b)
			up.pb(pip(i,pii(a,b)));
		else	
			down.pb(pip(i,pii(a,b)));
	}
	
	sort(up.begin(), up.end(), compu);
	sort(down.begin(), down.end(), compd);
	
	if(up.size() > down.size()){
		swap(up,down);
	}
	
	printf("%d\n",(int)down.size());
	for(int i=0;i<down.size();i++)
	//	printf("%d %d\n",1+down[i].second.first,1+down[i].second.second);
		printf("%d\n",1+down[i].first);
}