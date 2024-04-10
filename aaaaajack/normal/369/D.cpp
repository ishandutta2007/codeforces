#include<cstdio>
#include<queue>
#include<utility>
using namespace std;
bool z1[5000]={false},z2[5000]={false},h1[5000]={false},h2[5000]={false},v[3010][3010]={false};
int main(){
	int i,n,k,p[5000],count=1;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++) scanf("%d",&p[i]);
	z2[n]=true;
	for(i=n-1;i>=0;i--){
		if(p[i]==100){
			h1[i]=true;
			h2[i]=true;
		}
		else if(p[i]==0){
			z1[i]=true;
			if(z2[i+1]) z2[i]=true;
		}
		if(h2[i+1]){
			h2[i]=true;
		}
	}
	queue<pair<int,pair<int,int> > > q;
	q.push(make_pair(k,make_pair(0,1)));
	v[0][1]=true;
	while(!q.empty()){
		pair<int,pair<int,int> > s=q.front();
		int sing=s.second.first,cons=s.second.second,bull=s.first;
		q.pop();
		if(s.first>0&&s.second.second<n){
			if(!z1[sing]&&!z2[cons]&&!v[cons+1][cons+2]){
				v[cons+1][cons+2]=true;
				count++;	
				q.push(make_pair(bull-1,make_pair(cons+1,cons+2)));
			}
			if(!z1[sing]&&!h2[cons]&&!v[sing][cons+1]){
				v[sing][cons+1]=true;
				count++;
				q.push(make_pair(bull-1,make_pair(sing,cons+1)));
			}
			if(!h1[sing]&&!z2[cons]&&!v[cons][cons+1]){
				v[cons][cons+1]=true;
				count++;
				q.push(make_pair(bull-1,make_pair(cons,cons+1)));
			}
		}
	}
	printf("%d\n",count);
	return 0;
}