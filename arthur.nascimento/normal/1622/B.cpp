#include <bits/stdc++.h>

 

#define maxn 400400

#define pb push_back

#define debug 

#define mid ((ini+fim)/2)

#define ll long long

#define pii pair<int,int>


 

using namespace std;

int p[maxn];
char s[maxn];
int ans[maxn];


main(){

	int nt;
	scanf("%d",&nt);

	while(nt--){

		int n;
		scanf("%d",&n);

		vector<int> v;

		for(int i=0;i<n;i++)
			scanf("%d",p+i), v.pb(i);

		int q = 0;
		for(int i=0;i<n;i++)
			scanf(" %c",s+i), q += (s[i] == '0');

		sort(v.begin(), v.end(), [](int i,int j){
			return p[i] < p[j];
		});

		int p = 0;

		for(int i : v){
			if(s[i] == '0') ans[i] = p++;
			else ans[i] = q++;
		}	

		for(int i=0;i<n;i++)
			printf("%d ",1+ans[i]);

		printf("\n");
		
	}

}