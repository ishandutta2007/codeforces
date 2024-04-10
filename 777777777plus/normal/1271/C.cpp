#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n,sx,sy;
int x[N],y[N],c[4];

int main(){
	cin>>n>>sx>>sy;
	for(int i=1;i<=n;++i){
		cin>>x[i]>>y[i];
		x[i]-=sx;y[i]-=sy;
		if(x[i]==0)c[y[i]>0]++;
		else if(x[i]>0){
			c[2]++;
			if(y[i])c[y[i]>0]++;
		}
		else{
			c[3]++;
			if(y[i])c[y[i]>0]++;
		}
	}
	int w=*max_element(c,c+4);
	cout<<w<<endl;
	if(w==c[0]){
		cout<<sx<<" "<<sy-1<<endl;
	}
	else if(w==c[1]){
		cout<<sx<<" "<<sy+1<<endl;
	}
	else if(w==c[2]){
		cout<<sx+1<<" "<<sy<<endl;
	}
	else{
		cout<<sx-1<<" "<<sy<<endl;
	}
	return 0;
}