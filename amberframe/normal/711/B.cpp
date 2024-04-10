#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>

typedef long long LL;
#define pb push_back
using namespace std;
const int maxn = 1005;
LL a[maxn][maxn];
LL sum1=-1,sum2=-1;
int n;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("magic.in","r",stdin);
		freopen("magic.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		scanf("%I64d",&a[i][j]);
	if (n==1) {puts("1");return 0;}
	for (int i=1;i<=n;i++)
	{
		LL cur=0;bool tag=true;
		for (int j=1;j<=n;j++) {
			if (!a[i][j]) tag=false;
			cur+=a[i][j];
		}
		if (tag) {
			if (sum1<0) sum1=cur;
			if (sum1!=cur) {puts("-1");return 0;}
		}
		else {
			if (sum2<0) sum2=cur;
			if (sum2!=cur) {puts("-1");return 0;}
		}
	}
	for (int j=1;j<=n;j++)
	{
		LL cur=0;bool tag=true;
		for (int i=1;i<=n;i++) {
			if (!a[i][j]) tag=false;
			cur+=a[i][j];
		}
		if (tag) {
			if (sum1<0) sum1=cur;
			if (sum1!=cur) {puts("-1");return 0;}
		}
		else {
			if (sum2<0) sum2=cur;
			if (sum2!=cur) {puts("-1");return 0;}
		}
	}
	
	{
		LL cur=0;bool tag=true;
		for (int i=1;i<=n;i++) {
			if (!a[i][i]) tag=false;
			cur+=a[i][i];
		}
		if (tag) {
			if (sum1<0) sum1=cur;
			if (sum1!=cur) {puts("-1");return 0;}
		}
		else {
			if (sum2<0) sum2=cur;
			if (sum2!=cur) {puts("-1");return 0;}
		}
	}
	{
		LL cur=0;bool tag=true;
		for (int i=1;i<=n;i++) {
			if (!a[i][n-i+1]) tag=false;
			cur+=a[i][n-i+1];
		}
		if (tag) {
			if (sum1<0) sum1=cur;
			if (sum1!=cur) {puts("-1");return 0;}
		}
		else {
			if (sum2<0) sum2=cur;
			if (sum2!=cur) {puts("-1");return 0;}
		}
	}
	if (sum1<=sum2) {puts("-1");return 0;}
	printf("%I64d",sum1-sum2);
	return 0;
}