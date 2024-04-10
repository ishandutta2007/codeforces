#include <iostream>
#include <math.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int M=998244353;
int i,l,r,d,n,f[1005];
char a[100005],b[100005];
int main(){
	f['a']=f['e']=f['i']=f['o']=f['u']=1;
	scanf("%s\n%s",a,b);
	if(strlen(a)==strlen(b))
	{
		for(i=0;a[i];i++)
			if(f[a[i]]!=f[b[i]])
			{
				printf("No");
				return 0;
			}
		printf("Yes");
	}
	else
		printf("No");
}