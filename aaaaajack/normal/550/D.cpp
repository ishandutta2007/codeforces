#include<cstdio>
#include<vector>
using namespace std;
int main(){
	int k,num=3,i,j;
	vector<int> a,b,c,d;
	scanf("%d",&k);
	if(k%2==0){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	printf("%d %d\n",4*(k-1)+2,k*(2*k-1));
	printf("1 2\n");
	for(i=0;i<k-1;i++){
		a.push_back(num++);
		b.push_back(num++);
		c.push_back(num++);
		d.push_back(num++);
	}
	for(i=0;i<k-1;i++){
		printf("%d %d\n",1,a[i]);
		printf("%d %d\n",2,c[i]);
		for(j=0;j<k-1;j++){
			printf("%d %d\n",a[i],b[j]);
			printf("%d %d\n",c[i],d[j]);
		}
	}
	for(i=0;i<k-1;i+=2){
		printf("%d %d\n",b[i],b[i+1]);
		printf("%d %d\n",d[i],d[i+1]);
	}
	return 0;
}