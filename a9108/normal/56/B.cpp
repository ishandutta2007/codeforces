#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#define eps 1e-8
#define PB push_back
#define MP make_pair
using namespace std;
double pi=asin(1.0)*2;

int a[2000];
int n;

int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]),a[i]--;
	int po=-1;
	for (int i=0;i<n;i++) if (a[i]!=i){po=i;break;}
	if (po==-1){
		printf("0 0\n");
		return 0;
	}
	int l=po,r=a[po];
	for (int i=0;i<(r-l+1)/2;i++) swap(a[l+i],a[r-i]);
	bool ok=true;
	for (int i=0;i<n;i++) if (a[i]!=i) ok=false;
	if (ok) printf("%d %d\n",l+1,r+1);
	else printf("0 0\n");
	return 0;
}