#include<bits/stdc++.h>

#define c(x) a[x].val-a[x+1].val

using namespace std;

struct A{
	int val,id;
}a[3010];
bool cmp(A a1,A a2){return a1.val>a2.val;}
int n,x,y,z,to1,to2,i,j,k,an1,an2,an3,p[4],b[3010];

int main(){
	cin>>n;
	for (i=1;(a[i].id=i)<=n;i++) 
                cin>>a[i].val;
	sort(a+1,a+n+1,cmp);
	for (i=1;i<=n;i++){
		to1=min(i+i*2,n);
		for (j=i+(i+1)/2;j<=to1;j++){
			to2=min(j+min(i,j-i)*2,n);
			for (k=j+max(i+1,j-i+1)/2;k<=to2;k++){
				if (c(i)>an1||c(i)==an1&&c(j)>an2||c(i)==an1&&c(j)==an2&&c(k)>an3)
					an1=c(i),an2=c(j),an3=c(k),p[1]=i,p[2]=j,p[3]=k;
			}
		}
	}
	for (int i=1;i<=n;i++)
		b[a[i].id]=lower_bound(p+1,p+4,i)-p;
	for (int i=1;i<=n;i++)
		printf("%d ",b[i]==4?-1:b[i]);
}