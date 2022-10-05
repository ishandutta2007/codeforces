#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <cstdio>
#include <stdio.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define GG(a) cout<<"Bag is here!!!"<<a<<endl
using namespace std;
const int maxn=2e6+123;
int n,a[maxn],now,ans=maxn;
int main(){  
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++) {
		now=0   ;
		for(int j=i;j<n;j++){
			now+=a[j];
			ans=min(ans,abs(360-2*now));
		}
		}
	cout<<ans;
	return 0;
}