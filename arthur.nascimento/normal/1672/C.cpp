#include <bits/stdc++.h>
#define maxn 400400
#define pb push_back
#define debug 
#define mid ((ini+fim)/2)
#define ll long long
#define pii pair<int,int>
using namespace std;

char s[maxn];

int a[maxn];
int b[maxn];

int v[maxn];

main(){

	int nt;
	scanf("%d",&nt);

	while(nt--){

		int n;
		scanf("%d",&n);

		int f = -1, l = -1;

		for(int i=0;i<n;i++)
			scanf("%d",v+i);

		for(int i=0;i<n-1;i++)
			if(v[i] == v[i+1]){

				if(f == -1) f = i;
				l = i;
			}

		if(f == -1 || f == l) printf("0\n");
		else if(l == f+1) printf("1\n");
		else printf("%d\n",l-f-1);

	}

}