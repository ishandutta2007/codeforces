#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <vector>
#include <cstdio>
#include <stdio.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define iop(a) cout<<"Bag is here!!!"<<a<<endl
using namespace std;
const int maxn=2e5+123;
long long k[30],a,ans,p2[30];
set<long long >ms;
int main(){           
	p2[0]=1;
	for(int i=1;i<30;i++)
		p2[i]=p2[i-1]*2;
	for(int i=0;i<15;i++){
		k[i]=p2[2*i-1]-p2[i-1];
		ms.insert(k[i]);
	}
	cin>>a;
	for(int i=1;i<=sqrt(a);i++){
		if(a%i==0){
			if(ms.find(i)!=ms.end())
				ans=i;
			if(ms.find(a/i)!=ms.end()){
				cout<<a/i;
				return 0;
			}
		}
	}
	cout<<ans;
	return 0;
}