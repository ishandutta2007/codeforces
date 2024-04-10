#include<cstdio>
#include<vector>
#include<utility>
#define dis(a,b) ((a)-(b)>0?(a)-(b):(b)-(a))
using namespace std;
char c[2010][2010];
bool range(int i,int j,int u,int d,int l,int r){
	if((i==u||i==d)&&(j-l)*(j-r)<=0) return true;
	else if((j==l||j==r)&&(i-u)*(i-d)<=0) return true;
	return false;
}
int main(){
	int i,j,m,n;
	vector<pair<int,int> > white;
	vector<int> fix;
	scanf("%d%d",&m,&n);
	int l=n-1,r=0,u=m-1,d=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf(" %c",&c[i][j]);
			if(c[i][j]=='w'){
				white.push_back(make_pair(i,j));
				if(i<u) u=i;
				if(i>d) d=i;
				if(j<l) l=j;
				if(j>r) r=j;
			}
		}
	}
	if(dis(l,r)>dis(u,d)){
		for(i=0;i<white.size();i++){
			if(white[i].second!=l&&white[i].second!=r){
				if(fix.size()<=2){
					for(j=0;j<fix.size();j++){
						if(fix[j]==white[i].first) break;
					}
					if(j==fix.size()) fix.push_back(white[i].first);
				}
			}
		}
		if(fix.size()>2){
			printf("-1\n");
		}
		else if(fix.size()==2){
			if(dis(fix[0],fix[1])!=dis(l,r)){
				printf("-1\n");
			}
			else{
				for(i=0;i<m;i++){
					for(j=0;j<n;j++){
						if(c[i][j]=='w') putchar('w');
						else if(range(i,j,fix[0],fix[1],l,r)) putchar('+');
						else putchar('.');
					}
					putchar('\n');
				}
			}
		}
		else if(fix.size()==1){
			if(fix[0]<=u&&fix[0]+dis(l,r)>=d&&fix[0]+dis(l,r)<m){
				for(i=0;i<m;i++){
					for(j=0;j<n;j++){
						if(c[i][j]=='w') putchar('w');
						else if(range(i,j,fix[0],fix[0]+dis(l,r),l,r)) putchar('+');
						else putchar('.');
					}
					putchar('\n');
				}
			}
			else if(fix[0]>=d&&fix[0]-dis(l,r)<=u&&fix[0]-dis(l,r)>=0){
				for(i=0;i<m;i++){
					for(j=0;j<n;j++){
						if(c[i][j]=='w') putchar('w');
						else if(range(i,j,fix[0],fix[0]-dis(l,r),l,r)) putchar('+');
						else putchar('.');
					}
					putchar('\n');
				}
			}
			else{
				printf("-1\n");
			}
		}
		else{
			int ub=d-dis(l,r)>0?d-dis(l,r):0;
			int lb=u+dis(l,r)<m?u+dis(l,r):m-1;
			if(dis(ub,lb)>=dis(l,r)){
				for(i=0;i<m;i++){
					for(j=0;j<n;j++){
						if(c[i][j]=='w') putchar('w');
						else if(range(i,j,ub,ub+dis(l,r),l,r)) putchar('+');
						else putchar('.');
					}
					putchar('\n');
				}
			}
			else{
				printf("-1\n");
			}
		}
	}
	else{
		for(i=0;i<white.size();i++){
			if(white[i].first!=u&&white[i].first!=d){
				if(fix.size()<=2){
					for(j=0;j<fix.size();j++){
						if(fix[j]==white[i].second) break;
					}
					if(j==fix.size()) fix.push_back(white[i].second);
				}
			}
		}
		if(fix.size()>2){
			printf("-1\n");
		}
		else if(fix.size()==2){
			if(dis(fix[0],fix[1])!=dis(u,d)){
				printf("-1\n");
			}
			else{
				for(i=0;i<m;i++){
					for(j=0;j<n;j++){
						if(c[i][j]=='w') putchar('w');
						else if(range(i,j,u,d,fix[0],fix[1])) putchar('+');
						else putchar('.');
					}
					putchar('\n');
				}
			}
		}
		else if(fix.size()==1){
			if(fix[0]<=l&&fix[0]+dis(u,d)>=r&&fix[0]+dis(u,d)<n){
				for(i=0;i<m;i++){
					for(j=0;j<n;j++){
						if(c[i][j]=='w') putchar('w');
						else if(range(i,j,u,d,fix[0],fix[0]+dis(u,d))) putchar('+');
						else putchar('.');
					}
					putchar('\n');
				}
			}
			else if(fix[0]>=r&&fix[0]-dis(u,d)<=l&&fix[0]-dis(u,d)>=0){
				for(i=0;i<m;i++){
					for(j=0;j<n;j++){
						if(c[i][j]=='w') putchar('w');
						else if(range(i,j,u,d,fix[0],fix[0]-dis(u,d))) putchar('+');
						else putchar('.');
					}
					putchar('\n');
				}
			}
			else{
				printf("-1\n");
			}
		}
		else{
			int ub=r-dis(u,d)>0?r-dis(u,d):0;
			int lb=l+dis(u,d)<n?l+dis(u,d):n-1;
			if(dis(ub,lb)>=dis(u,d)){
				for(i=0;i<m;i++){
					for(j=0;j<n;j++){
						if(c[i][j]=='w') putchar('w');
						else if(range(i,j,u,d,ub,ub+dis(u,d))) putchar('+');
						else putchar('.');
					}
					putchar('\n');
				}
			}
			else{
				printf("-1\n");
			}
		}
	}
	return 0;
}